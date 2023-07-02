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
#include <thread>
using std::thread;


// I moved the lines vector to global section 
// because is a shared resources.
// Each thread works in a different sector so
// we do not need a mutex to protect it
vector<string> lines;
// I create this vector for the output string
// to avoid the problems with the output 
// from different threads on cout
vector<string> output_lines;

int get_start(int no_of_elements, int no_of_workers, int worker_id)
{
	const int num_tasks = no_of_elements/no_of_workers;
	const int num_tougher_threads = no_of_elements%no_of_workers;

	if (worker_id < num_tougher_threads)
		return (worker_id * (num_tasks + 1));
	else
		return no_of_elements - (no_of_workers - worker_id) * num_tasks;
}

int get_end(int start, int no_of_elements, int no_of_workers, int worker_id)
{
	const int num_tasks = no_of_elements/no_of_workers;
	const int num_tougher_threads = no_of_elements%no_of_workers;
	return start + num_tasks + (worker_id < num_tougher_threads) - 1 ;
}

void search_thread(int thid, int start, int end, string string_to_find) 
{	
	for (int i = start; i <=end; ++i) {
		std::size_t found = lines.at(i).find(string_to_find);
		if (found != std::string::npos) {
			output_lines.at(thid).append(lines.at(i) + "\n");
		}
	}
}

	
int main (int argc, char* argv[]) 
{
	// check the input and get input parameters	
	if (argc!= 4) {
		cout << "missing command line arguments:\n";
		cout << "to run ./main filename string_to_find no_of_workers\n";
		exit(EXIT_FAILURE);
	}
	string filename{argv[1]};
	string string_to_find{argv[2]};
	int no_of_workers{atoi(argv[3])};

	// open the file and store its content in a vector	
	ifstream myfile(filename);
	if (!myfile.is_open()) {
		cout << "unable to open file: " << filename << "\n";
		exit(EXIT_FAILURE);
  	}
	string a_line;
	while (getline (myfile, a_line))
		lines.push_back(a_line);
	myfile.close();

	
	
	output_lines.resize(no_of_workers,""); // set a string for each worker


	std::vector<std::thread> workers;
	for(int i=0; i<no_of_workers; ++i)	{
		int start = get_start(lines.size(), no_of_workers, i);
		int end = get_end(start, lines.size(), no_of_workers, i);
		cout << "Start thread:" << i << " lines: " << start << "-" << end <<endl; 
		workers.push_back( thread{search_thread, i, start, end, string_to_find});
	}

    // wait the end of the threads and print the results
	std::vector<std::thread>::iterator worker;
	for (worker=workers.begin(); worker != workers.end(); ++worker)
		worker->join();

	for (int i = 0; i < no_of_workers; ++i)
		cout << output_lines.at(i);
		
	std::cout<<"\nend of Main Thread"<<std::endl;
	return 0;
}

