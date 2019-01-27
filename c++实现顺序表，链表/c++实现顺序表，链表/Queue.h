#pragma once
#include"Seqlist.h"
#include"list.h"
//使用容器适配器实现队列
template<class T, class Container = list<T>>
class Queue
{
public:
	void PopFront()
	{
		_con.PopFront();
	}
	void PushBack(const T& x)
	{
		_con.PushBack(x);
	}
	size_t Size()
	{
		return _con.Size();
	}
	bool Empty()
	{
		return _con.Empty();
	}
	void Print()
	{
		_con.Print();
	}

private:
	Container _con;
};

void TestQueue()
{
	Queue<int, list<int>> q1;
	q1.PushBack(1);
	q1.PushBack(2);
	q1.PushBack(3);
	q1.PushBack(4);
	q1.PushBack(5);
	q1.Print();
	q1.PopFront();
	q1.Print();
	std::cout << q1.Size() << std::endl;
	std::cout << q1.Empty() << std::endl;

}