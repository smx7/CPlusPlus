#include<iostream>
using namespace std;
//class A
//{
//public:
//	A(int a1)
//	{
//		a = a1;
//	}
//	virtual void fun1()
//	{
//		cout << "基类虚函数" << endl;
//	}
//	virtual void fun2()
//	{
//
//	}
//private:
//	int a;
//};
//class B :public A
//{
//public:
//	B(int a1, int b1) :A(a1)
//	{
//		b = b1;
//	}
//	virtual void fun1()
//	{
//		cout << "派生类虚函数" << endl;
//	}
//	virtual void fun2()
//	{
//
//	}
//private:
//	int b;
//};
//void print1(A *p)
//{
//	p->fun1();
//}
//void print2(A &p)
//{
//	p.fun1();
//}
//void print3(A p)
//{
//	p.fun1();
//}
//int main()
//{
//	A aa(10);
//	B bb(20, 30);
//	//aa.fun1();
//	//bb.fun1();
//	//print1(&aa);
//	//print1(&bb);
//	//print2(aa);
//	//print2(bb);
//	//print3(aa);
//	//print3(bb);
//	system("pause");
//	return 0;
//
//}

//单继承的虚指针和虚表
//class A
//{
//public:
//	virtual void fun1()
//	{
//		cout << "A::fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "A::fun2()" << endl;
//	}
//};
//class B :public A
//{
//public:
//	virtual void fun1()
//	{
//		cout << "B::fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "B::fun2()" << endl;
//	}
//};
//typedef void (*FUNC)();
//
//void printVtable(int *vfptr)
//{
//	cout << "虚表地址：" << vfptr << endl;
//	for (int i = 0; vfptr[i] != 0; i++)   //虚表最后一个元素是0
//	{
//		printf("第%d个虚函数地址：0x%x,->", i, vfptr[i]);
//		FUNC f = (FUNC)vfptr[i];
//		f(); //调用该虚函数
//	}
//	cout << endl;
//}
//
//int main()
//{
//	A a;
//	B b;
//	int *vfptr1 = (int*)(*(int*)(&a));
//	int *vfptr2 = (int*)(*(int*)(&b));
//	printVtable(vfptr1);
//	printVtable(vfptr2);
//	system("pause");
//	return 0;
//}

class A
{
public:
	virtual void fun1()
	{
		cout << "A::fun1()" << endl;
	}
	virtual void fun2()
	{
		cout << "A::fun2()" << endl;
	}
protected:
	int a;

};
class B
{
public:
	virtual void fun1()
	{
		cout << "B::fun1()" << endl;
	}
	virtual void fun2()
	{
		cout << "B::fun2()" << endl;
	}
protected:
	int b;
};
class C :public A, public B
{
public:
	virtual void fun1()
	{
		cout << "C::fun1()" << endl;
	}

	virtual void fun3()
	{
		cout << "C::fun3()" << endl;
	}
protected:
	int c;

};
typedef void(*FUNC)(); //声明一个函数指针类型FUNC

void printTable(int *vfptr)
{
	cout << "虚表地址：" << vfptr << endl;
	for (int i = 0; vfptr[i] != 0; i++)
	{
		printf("第%d个虚函数地址:%p->", i, vfptr[i]);
		FUNC f = (FUNC)(vfptr[i]);
		f();  //调用这个函数
	}
	cout << endl;
}
int main()
{
	C c;
	cout << sizeof(c) << endl;
	int *vfptr1 = (int*)(*((int*)(&c)));
	printTable(vfptr1);
	//因为第二个虚表指针存放在第一个父类成员变量下边，所以第二个虚表指针在&c后需要加上第一个父类的大小，
	//但是由于指针+1，加的是所指类型的大小，所以需要把&a强转为char*,或者+sizeof(A)/4,
	int *vfptr2 = (int*)(*(int*)(((char*)(&c)) + sizeof(A)));
	printTable(vfptr2);
	system("pause");
	return 0;

}