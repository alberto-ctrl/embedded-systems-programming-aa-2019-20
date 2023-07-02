/*
** server.c -- a stream socket server demo
*/

#include "IOManagement.h"
#include "PaymentsManagement.h"
#include "BookingsManagement.h"

#include <vector>
using std::vector;
#include <mutex>
using std::mutex;
#include <condition_variable>
using std::condition_variable;

// global variable for the parkings
Parking P1{"PARK1", 200};
Parking P2{"PARK2", 100};

vector<Car> next_car(7,Car());      // global vector for manage the events, initialized with default Car() data
mutex mtx;                          // global mutex
condition_variable ok_advance;
condition_variable ok_update_fee;

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <thread>
using std::thread;


const int MAXDATASIZE{10}; // max number of bytes we can get at once


void new_connection (int sock) {

  char buf[MAXDATASIZE];
  int actions_id{0};
  char earn_P1[MAXDATASIZE];
  char earn_P2[MAXDATASIZE];

  if ((numbytes = recv(sockfd, buf, 2, 0)) == -1) {
	    cerr << "Client failed to receive data\n";
	    exit(EXIT_FAILURE);
	}

  buf[numbytes] = '\0';
  actions_id=(int)buf;

  if (actions_id==1) {
    if (send(sock, (*char)P1.total_gain(), 13, 0) == -1)
		cerr << "error server sending\n";
  }
  if (actions_id==2) {
    if (send(sock, (*char)P2.total_gain(), 13, 0) == -1)
		cerr << "error server sending\n";
  }

  cout << "\n BENEEEEEEEEEEEEEEE" << endl;
	close(sock);
}


// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int make_accept_sock (const char* port) {

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints) );
    hints.ai_family   = AF_UNSPEC; // PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE; // use my IP

    struct addrinfo* servinfo;
    int rv = getaddrinfo(NULL, port, &hints, &servinfo);
    if (rv != 0) {
        cerr << "getaddrinfo:" << gai_strerror(rv) << endl;
        exit(EXIT_FAILURE);
    }

    struct addrinfo  *p;
    int sockfd; int yes{1};
    // loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {

        // create a socket
        // socket(int domain, int type, int protocol)
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			cerr << "server: failed to create socket\n";
			continue;
		}

		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
				sizeof(int)) == -1) {
			cerr << "server: failed setsockopt\n";
			exit(EXIT_FAILURE);
		}

        // bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
        // bind() passes file descriptor, the address structure,
        // and the length of the address structure
        // This bind() call will bind the socket to the current IP address
        // on port
		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			cerr << "server: failed bind\n";
			continue;
		}

		break;
	}

	if (p == NULL)  {
		cerr << "server: failed to bind\n";
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(servinfo); // all done with this structure

    // This listen() call tells the socekt to listen to the incoming connections.
    // The listen() function places all incoming connection into a backlog queue
    // until accept() call accepts the connection
    // Here we set the maximum size for the backlog queue to 10.

    const int BACKLOG{10};	 // how many pending connections queue will hold
	if (listen(sockfd, BACKLOG) == -1) {
		cerr << "server: failed to listen\n";
	    exit(EXIT_FAILURE);
	}

    return sockfd;

}


void accept_loop (const char* port) {
    // create the accept socket
    int sock = make_accept_sock(port);

    while(true) {
        // the accept() call actually accepts an incoming connection
        // This accept() function will write the connecting client's address info
        // into the the address structure and the size of that structure is clilen.
        // The accept() returns a new socket file descriptor for the accepted connection.
        // So, the original socket file descriptor can continue to be used
        // for accepting new connections while the new socker file descriptor is used for
        // communicating with the connected client.
        int new_sock = accept(sock, 0, 0);
        if (new_sock < 0) {
            cerr << "server: failed on accept\n";
            exit(EXIT_FAILURE);
        }
        std::thread t(new_connection, new_sock);
        t.detach();
    }
}




int main(int argc, char* argv[])
{
    thread input_P1{io_management, 0};
    thread output_P1{io_management, 1};
    thread input_P2{io_management, 2};
    thread output_P2{io_management, 3};

    thread fee{payments_managements};

    thread reservations{booking_management};


    if (argc != 2) {
        cerr << "usage: ./server port\n";
        exit(EXIT_FAILURE);
    }

    accept_loop(argv[1]);

    input_P1.join();
    output_P1.join();
    input_P2.join();
    output_P2.join();

    fee.join();

    reservations.join();

	return 0;
}
