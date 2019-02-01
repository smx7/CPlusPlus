#include<iostream>
#include<deque>
using namespace std;

template<class T,class Container=deque<T>>
class stack
{
public:
	void push(const T& x)
	{
		con.push_back(x);
	}
	void pop()
	{
		con.pop_back();
	}
	size_t size()
	{
		return con.size();
	}
	bool empty()
	{
		return con.empty();
	}
	T& top()
	{
		return con.back();
	}
	const T& top() const
	{
		return con.back();
	}
private:
	Container con;
};
template<class T,class Container=deque<T>>
class queue
{
public:
	void push(const T& x)
	{
		con.push_back(x);
	}
	void pop()
	{
		con.pop_front();
	}
	size_t size()
	{
		return con.size();
	}
	bool empty()
	{
		return con.empty();
	}
	T& front()
	{
		return con.front();
	}
	const T& front() const
	{
		return con.front();
	}
	T& back()
	{
		return con.back();
	}
	const T& back() const
	{
		return con.back();
	}
private:
	Container con;
};
int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;

	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;
	q.pop();
	q.pop();
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;



	system("pause");
	return 0;
}