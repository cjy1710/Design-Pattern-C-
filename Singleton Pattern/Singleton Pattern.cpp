#include<iostream>
#include<thread>
#include<Windows.h>
#include<mutex>
using namespace std;
/*
//懒汉式 线程安全
class Singleton
{
	private:
		Singleton()
		{
			std::cout << "Constructure Init"<<std::endl;
			m_count = 0;
		}
		~Singleton()
		{
			std::cout << "Destructor End"<<std::endl;
		}
		static Singleton* m_instance;
		static mutex _mutex;
		int m_count;
	public:
		static Singleton* GetInstance()
		{
			if (m_instance == nullptr)
			{
				lock_guard<std::mutex> lock(_mutex);
				if (m_instance == nullptr)
				{
					m_instance = new Singleton();
				}
			}
			return m_instance;
			
		}
		void add();
};

 Singleton* Singleton::m_instance = nullptr;
 mutex Singleton::_mutex;

 */

class Singleton
{
private:
	Singleton()
	{
		std::cout << "Constructure Init" << std::endl;
		m_count = 0;
	}
	~Singleton()
	{
		std::cout << "Destructor End" << std::endl;
	}
	static Singleton* m_instance;
	int m_count;
public:
	static Singleton* GetInstance()
	{
		return m_instance;
	}
	void add();
};

Singleton* Singleton::m_instance = new Singleton();


void fun()
{
	Singleton::GetInstance()->add();
}

void Singleton::add()
{
	Singleton::GetInstance()->m_count++;
	cout << m_count << endl;
}

int main()
{
	
	thread t1(fun);
	thread t2(fun);
	t1.join();
	t2.join();

}