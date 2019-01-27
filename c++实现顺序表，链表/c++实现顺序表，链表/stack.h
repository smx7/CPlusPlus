#pragma once
#include"Seqlist.h"
#include"list.h"
//使用容器适配器实现栈
template<class T,class Container=Seqlist<T>>
class stack
{
public:
	void Push(const T& x)
	{
		_con.PushBack(x);
	}
	void Pop()
	{
		_con.PopBack();
	}
	const T & Top()
	{
		
	}
	bool Empty()
	{
		return _con.Empty();
	}
	size_t Size()
	{
		return _con.Size();
	}
	void Print()
	{
		_con.Print();
	}

private:
	Container _con;
};
void Teststack()
{
	stack<int, Seqlist<int>> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	s1.Print();
	s1.Pop();
	s1.Print();
	std::cout << s1.Size() << std::endl;
	std::cout << s1.Empty() << std::endl;

	stack<char, Seqlist<char>> s2;
	s2.Push('s');
	s2.Push('h');
	s2.Push('i');
	s2.Push('o');
	s2.Print();

}