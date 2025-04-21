#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
	using namespace std::literals::chrono_literals;

	std::cout << std::this_thread::get_id() << std::endl;

	while (!s_Finished)
	{
		std::cout << "working...\n";
		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	std::thread worker(DoWork);

	std::cin.get();
	s_Finished = true;

	worker.join();//主线程执行到这句代码，就无法继续向下执行了，要等待worker线程执行完毕，才可以继续向下执行。在这句代码之前，主线程和worker是并行的。
	std::cout << "Finished" << std::endl;
	std::cout << std::this_thread::get_id() << std::endl;

	std::cin.get();
}