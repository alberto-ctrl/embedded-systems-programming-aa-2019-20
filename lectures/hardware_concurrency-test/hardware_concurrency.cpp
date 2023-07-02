#include <thread>
#include <iostream>

int main() 
{
	std::cout << "Number of tasks that can simultaneously proceed: " << std::thread::hardware_concurrency() << std::endl;
}
