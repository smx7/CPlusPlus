#include<iostream>
using namespace std;
class A
{
public:
	A(int a1)
	{
		a = a1;
		cout <<"构造函数A"<< endl;
	}
	void print()
	{
		cout << a << endl;
	}
private:
	int a;
};
class A1
{
public:
	A1(int a2)
	{
		a1 = a2;
		cout << "构造函数A1" << endl;
	}
	void print()
	{
		cout << a1<< endl;
	}
private:
	int a1;
};
class B :virtual public A
{
public:
	B(int a1, int b1) :A(a1)
	{
		b = b1;
		cout << "构造函数B" << endl;
	}
	void printf()
	{
		cout << b << endl;
	}
private:
	int b;
};
class C :virtual public A
{
public:
	C(int a1, int c1) :A(a1)
	{
		c = c1;
		cout << "构造函数C" << endl;
	}
	void print()
	{
		cout << c << endl;
	}
private:
	int c;
};
class D :public A, public A1
{
public:
	D(int a1, int a2, int d1) :A(a1), A1(a2)
	{
		d = d1; 
		cout << "构造函数D" << endl;
	}
	void print()
	{
		cout << d << endl;
	}
private:
	int d;
};
class E :public B, virtual public C
{
public:
	E(int a1, int b1, int c1, int e1) :A(a1), B(a1, b1), C(a1, c1)
	{
		e = e1;
		cout << "构造函数E" << endl;
	}
	void print()
	{
		cout << e << endl;
	}
private:
	int e;
};
int main()
{
	//D dd(20, 30, 40);
	//dd.A::print();
	//dd.A1::print();
	//dd.print();
	B(10, 20);
	//E ee(1, 2, 3, 4);
	system("pause");
	return 0;
}