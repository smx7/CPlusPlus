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
//		cout << "�����麯��" << endl;
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
//		cout << "�������麯��" << endl;
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

//���̳е���ָ������
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
//	cout << "����ַ��" << vfptr << endl;
//	for (int i = 0; vfptr[i] != 0; i++)   //������һ��Ԫ����0
//	{
//		printf("��%d���麯����ַ��0x%x,->", i, vfptr[i]);
//		FUNC f = (FUNC)vfptr[i];
//		f(); //���ø��麯��
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
typedef void(*FUNC)(); //����һ������ָ������FUNC

void printTable(int *vfptr)
{
	cout << "����ַ��" << vfptr << endl;
	for (int i = 0; vfptr[i] != 0; i++)
	{
		printf("��%d���麯����ַ:%p->", i, vfptr[i]);
		FUNC f = (FUNC)(vfptr[i]);
		f();  //�����������
	}
	cout << endl;
}
int main()
{
	C c;
	cout << sizeof(c) << endl;
	int *vfptr1 = (int*)(*((int*)(&c)));
	printTable(vfptr1);
	//��Ϊ�ڶ������ָ�����ڵ�һ�������Ա�����±ߣ����Եڶ������ָ����&c����Ҫ���ϵ�һ������Ĵ�С��
	//��������ָ��+1���ӵ�����ָ���͵Ĵ�С��������Ҫ��&aǿתΪchar*,����+sizeof(A)/4,
	int *vfptr2 = (int*)(*(int*)(((char*)(&c)) + sizeof(A)));
	printTable(vfptr2);
	system("pause");
	return 0;

}