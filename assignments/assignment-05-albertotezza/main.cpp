// main.cpp

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <thread>
using std::thread;
#include <mutex>
using std::mutex;

// Global variables
vector<string> lines;
mutex my_semaphore;

void worker_thread(int ti, int t, string s_to_find)
{
	for (int i=ti; i < (static_cast<int>(lines.size())); i+=t) {
		//cout << "ciao " << i << s_to_find << endl;
		std::size_t found = lines[i].find(s_to_find);
			if(found != std::string::npos) {
				my_semaphore.lock();
				cout << endl << lines[i] << endl << " at line: " << i << endl << " from thread: " << ti << endl;
				my_semaphore.unlock();
			}
		}
}

int main (int argc, char* argv[])
{

	if (argc!= 4) {
		cout << "missing command line arguments:\n";
		cout << "to run ./main filename string_to_find no_of_workers\n";
		exit(EXIT_FAILURE);
	}
	string filename{argv[1]};						// NOME DEL FILE
	string string_to_find{argv[2]};			// STRINGA DA CERCARE
	int no_of_workers{atoi(argv[3])};		// NUMERO DI TREAD CHE ABBIAMO A DISPOSIZIONE

	// open the file
	ifstream myfile(filename);
	if (!myfile.is_open()) {
		cout << "unable to open file: " << filename << "\n";
		exit(EXIT_FAILURE);
  	}

	// store the lines in the vector (RIGA PER RIGA VA RIEMPIRE L'ARRAY DI STRINGHE)
	// vector<string> lines; // lo metto globale
	string a_line;
	while (getline (myfile, a_line))
		lines.push_back(a_line);
	myfile.close();

	// now it's your turn!
	/*
	(CREARE N THREAD,
	PRENDERE IL VETTORE (x righe) E DIVIDERLO IN N PARTI (x:N),
	OGNI THREAD LAVORERA' SU UNA PARTE DIVERSA DEL VETTORE COSI' LE THREAD POSSONO PROSEGUIRE PARALLELAMENTE,
	OGNI LINEA CHE POSSIEDE LA STRINGA CHE CERCHIAMO DEVE ESSERE STAMPATA CON COUT,
	1 PROBLEMA:
	SEPARARE LE x RIGHE IN MODO EQUO ANCHE SE x NON E' MULTIPLO DEGLI N WORKERS
	2 PROBLEMA:
	COUT E' RISORSA CONDIVISA, LE LINEE VERRANNO MESCOLATE
	)
	*/
	// controllo quante linee possiede il filename
	// cout << "\n il file inserito è composto da ( " << lines.size() << " ) righe.\n";

	// divido il vettore di linee in parti uguali

	vector<thread> worker;


	for (int i=0; i<no_of_workers; ++i) {
		worker.push_back(thread{worker_thread, i, no_of_workers, string_to_find});
	}

	vector<thread>::iterator i_worker;
	for(i_worker=worker.begin(); i_worker!=worker.end(); i_worker++)
		i_worker->join();

	cout << "Exit dalla main thread" << endl;

  return 0;
}
