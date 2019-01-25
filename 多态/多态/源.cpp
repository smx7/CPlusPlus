#include<iostream>
using namespace std;

//class A
//{
//public:
//	A(int _a) :a(_a)
//	{
//	}
//	virtual void fun() 
//	{
//		cout << "基类虚函数" << endl;
//	}
//protected:
//	int a;
//};
//
//class B :public A
//{
//public:
//	B(int _a, int _b) :A(_a), b(_b)
//	{}
//	virtual void fun() override
//	{
//		cout << "派生类虚函数" << endl;
//	}
//protected:
//	int b;
//};
//
//int main()
//{
//	A obj_a(10);
//	B obj_b(20, 30);
//
//	A aa = obj_b;
//	aa.fun();
//	A* paa = &obj_b;
//	paa->fun();
//	A& raa = obj_b;
//	raa.fun();
//
//	paa = &obj_a;
//	B* pbb = (B*)paa;
//	pbb->fun();
//
//	paa = &obj_b;
//	pbb = (B*)paa;
//	pbb->fun();
//
//
//
//
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//
//	}
//	void show()
//	{
//		cout << "基类函数" << endl;
//	}
//
//};
//class B :public A
//{
//public:
//	B() 
//	{
//	}
//	void show()
//	{
//		cout << "派生类函数" << endl;
//	}
//
//};
//int main()
//{
//	B obj_b;
//	A* a = &obj_b;
//
//	a->show();
//
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "基类析构函数" << endl;
//	}
//};
//class B:public A
//{
//public:
//	virtual ~B()
//	{
//		cout << "派生类析构函数" << endl;
//	}
//};
//int main()
//{
//	A* p = new B;
//	delete p;
//
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	virtual void show()
//	{
//		cout << "基类虚函数" << endl;
//	}
//};
//class B :public A
//{
//public:
//	virtual void show() override
//	{
//		cout << "派生类虚函数" << endl;
//	}
//
//};

class A 
{
public:
	virtual void show() final
	{

	}
};
class B :public A
{
	virtual void show()  //不能重写
	{

	}
};
