#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class A
//{
//public:
//	A(int a1)
//	{
//		a = a1;
//		cout << "基类构造函数" << endl;
//	}
//	A(const A& obj)
//	{
//		a = obj.a;
//		cout << "基类拷贝构造" << endl;
//	}
//	A& operator=(const A& obj)
//	{
//		if (this != &obj)
//		{
//			a = obj.a;
//		}
//		cout << "基类赋值运算符重载" << endl;
//		return *this;
//	}
//	void print1()
//	{
//		cout << a << endl;
//	}
//	~A()
//	{
//		cout << "基类析构函数" << endl;
//	}
//private:
//	int a;
//};
//class B: public A
//{
//public:
//	B(int a1, int b1) :A(a1), _a(a1)
//	{
//		b = b1;
//		cout << "派生类构造函数" << endl;
//	}
//	B(const B& obj) :A(obj), _a(obj), b(obj.b)
//	{
//		cout << "派生类拷贝构造" << endl;
//	}
//	B& operator=(const B& obj)
//	{
//		if (this != &obj)
//		{
//			this->A::operator=(obj);
//			_a = obj._a;
//			b = obj.b;
//		}
//		cout << "派生类赋值运算符重载" << endl;
//		return *this;
//	}
//	void print2()
//	{
//		A::print1();
//		_a.print1();
//		cout << b << endl;
//	}
//	~B()
//	{
//		cout << "派生类析构函数" << endl;
//	}
//private:
//	int b;
//	A _a;
//};
//int main()
//{
//	A aa1(10);
//	B bb1(20, 30);
//
//	B bb2 = bb1;
//	bb1 = bb2;
//
//	aa1.print1();
//	bb1.print2();
//	bb2.print2();
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	A(int _a1, int _a2) :a1(_a1), a2(_a2)
//	{
//	}
//	void print_A()
//	{
//		cout << a1 << " " << a2 << endl;
//	}
//protected:
//	int a1;
//	int a2;
//};
//class B :public A
//{
//public:
//	B(int _a1,int _a2,int _b) :A(_a1,_a2),b(_b)
//	{}
//	void print_B()
//	{
//		cout << a1 << " " << a2 << " " << b << endl;
//	}
//private:
//	int b;
//};
//
//int main()
//{
//	A obj_a(1, 2);
//	B obj_b(4, 5, 6);
//	obj_a.print_A();
//	obj_b.print_B();
//
//	obj_a = obj_b;
//	A *pobj_a = &obj_b;
//	A &qobj_a = obj_b;
//
//	obj_a.print_A();
//	pobj_a->print_A();
//	qobj_a.print_A();
//
//	B *pobj_b = (B*)pobj_a;
//	pobj_b->print_B();
//
//	pobj_a = &obj_a;
//	pobj_b = (B*)pobj_a;
//	pobj_b->print_B();
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
//	A(int _a) :a(_a)
//	{}
//	void print()
//	{
//		cout << a << endl;
//	}
//private:
//	int a;
//};
//class B :public A
//{
//public:
//	B(int _a) :A(_a)
//	{
//	}
//
//};
//int main()
//{
//	A obj_a(10);
//	B* p = &obj_a;
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	void print()
//	{
//		cout << a << endl;
//	}
//protected:
//	int a = 10;
//};
//class B :public A
//{
//public:
//	void print()
//	{
//		cout << a << endl;
//		cout << A::a << endl;
//	}
//protected:
//	int a = 20;
//};
//int main()
//{
//	B obj_b;
//	obj_b.print();
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	void print()
//	{
//		cout << "基类成员函数" << endl;
//	}
//	int x = 10;
//};
//class B :private A
//{
//public:
//	A::print;
//	A::x;
//};
//int main()
//{
//	B obj;
//	obj.print();
//	cout << obj.x << endl;
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//	}
//	void show1()
//	{
//		x++;
//		y++;
//		cout << x << endl;
//		cout << y << endl;
//	}
//protected:
//	static int x;
//	int y = 10;
//};
//int A::x = 10;
//class B :public A
//{
//public:
//	B()
//	{
//	}
//	void show2()
//	{
//		x++;
//		y++;
//		cout << x << endl;
//		cout << y << endl;
//	}
//};

//int main()
//{
//	A a;
//	a.show1();
//	B b;
//	b.show2();
//	system("pause");
//	return 0;
//}

class A
{
public:
	int a = 100;
};
class B :virtual public A
{
public:
	int b = 200;
};
class C :virtual public A
{
public:
	int c = 300;
};
class D :public B, public C
{
public:
	int d = 400;
};
int main()
{
	A obj_a;
	B obj_b;
	C obj_c;
	D obj_d;
	cout << sizeof(obj_a) << endl;
	cout << sizeof(obj_b) << endl;
	cout << sizeof(obj_c) << endl;
	cout << sizeof(obj_d) << endl;

	cout <<"B的虚基表指针地址："<< &obj_d << endl;
	cout << "成员b的地址：" << &obj_d.b << endl;
	cout << "C的虚基表指针地址：" << (int*)&obj_d +2<< endl;
	cout << "成员c的地址：" << &obj_d.c << endl;
	cout << "成员d的地址：" << &obj_d.d << endl;
	cout << "成员a的地址：" << &obj_d.a << endl;

	cout << "B的虚基表的第一项：" << *(int*)(*(int*)(&obj_d)) << endl;
	cout << "B的虚基表的第二项：" << *((int*)(*(int*)(&obj_d)) + 1) << endl;
	cout << "b的值为：" << *((int*)(&obj_d) + 1) << endl;

	cout <<"C的虚基表的第一项："<< *(int*)(*((int*)(&obj_d) + 2)) << endl;
	cout <<"C的虚基表的第二项："<< *((int*)(*((int*)(&obj_d) + 2)) + 1) << endl;
	cout << "c的值为：" << *((int*)(&obj_d) + 3) << endl;

	cout << "d的值为：" << *((int*)(&obj_d) + 4) << endl;
	cout << "a的值为：" << *((int*)(&obj_d) + 5) << endl;


	system("pause");
	return 0;
}


//class A
//{
//public:
//	int a = 100;
//};
//class B :public A
//{
//public:
//	int b = 200;
//};
//class C :public A
//{
//public:
//	int c = 300;
//};
//class D :public B, public C
//{
//public:
//	int d = 400;
//};
//int main()
//{
//	D obj;
//	//obj.a=1;
//	obj.B::a = 2;
//	obj.C::a = 3;
//
//	system("pause");
//	return 0;
//}