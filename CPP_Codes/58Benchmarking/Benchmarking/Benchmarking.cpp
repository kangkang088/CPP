#include <iostream>
#include <chrono>
#include <array>

class Timer
{
public:
	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		m_EndTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(m_EndTimepoint).time_since_epoch().count();

		auto duration = end - start;

		double ms = duration * 0.001;

		std::cout << duration << "us (" << ms << "ms)" << std::endl;
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint, m_EndTimepoint;
};

//benchmarking:基准测试，当你写了一些代码，你想知道它实际 运行 有多快，和过去的方法做个比较，看看哪个更快。基准测试的答案不唯一。
int main()
{
	int value = 0;
	{
		Timer timer;
		for (int i = 0; i < 100000; i++)
			value += 2;
	}

	std::cout << value << std::endl;
	//上述代码其实测试了一个寂寞：通过汇编，我们可以看到，上述计算其实在编译时就被优化了，编译器意识到这并不需要在运行时计算，直接在编译时就计算了
	//运行时就相当于进行了一次打印，我们测的是这个打印的时间。。。。甚至都不是，因为计时器范围没有包括打印。

	std::cout << "---------------------------------------------\n";

	struct Vector2
	{
		float x, y;
	};

	std::cout << "Make shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
		{
			sharedPtrs[i] = std::make_shared<Vector2>();
		}
	}
	std::cout << "New shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
		{
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
		}
	}
	std::cout << "Make unique\n";
	{
		std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
		Timer timer;
		for (int i = 0; i < uniquePtrs.size(); i++)
		{
			uniquePtrs[i] = std::make_unique<Vector2>();
		}
	}

	std::cin.get();
}