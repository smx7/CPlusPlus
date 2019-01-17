#include<iostream>
#include<string.h>

using namespace std;

//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	String s1("hello");
//	String s2(s1);
//}

//class A
//{
//public:
//	A(int _a,double _b)
//	{
//		a = _a;
//		b = _b;
//	}
//	virtual void print()
//	{
//		cout << "print()" << endl;
//	}
//private:
//	int a;
//	double b;
//	static int c;
//};
//int A::c = 30;
//int main()
//{
//	A obj(10, 20.5);
//	cout << *(int*)&obj << endl;
//	cout << sizeof(int) << endl;
//	cout << sizeof(double) << endl;
//	cout << sizeof(A) << endl;
//	cout << sizeof(obj) << endl;
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//
//	}
//	virtual void print()
//	{
//		cout << "virtual" << endl;
//	}
//private:
//	int a;
//	char arr[9];
//	double b;
//};
//
//int main()
//{
//	A obj;
//	cout << sizeof(A) << endl;
//	cout << sizeof(obj) << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	A(int _a,int _b)
//	{
//		a = _a; 
//		b = _b;
//	}
//	void show()
//	{
//		cout << a << endl;
//		cout << b << endl;
//	}
//private:
//	int a;
//	int b;
//};
//
//int main()
//{
//	A obj(10, 20);
//	obj.show();
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//	}
//	void print()
//	{
//		cout << a << endl;
//	}
//private:
//	int a = 10;
//
//};
//
//int main()
//{
//	A obj;
//	obj.print();
//
//	return 0;
//}

class A
{
public:
	A(int _a) :a(_a)
	{
	}
	void print()
	{
		cout << a << endl;
	}
	class B
	{
	public:
		B(int _b) :b(_b)
		{}
		void print(const A& obj)
		{
			cout << obj.a << endl;
			cout << b << endl;
			cout << aa << endl;
		}
	private:
		int b;
	};
private:
	int a;
	static int aa;
};
int A::aa = 100;
int main()
{
	A obj1(10);
	A::B obj2(20);
	obj2.print(obj1);
	cout << sizeof(A) << endl;
	cout << sizeof(A::B) << endl;

	return 0;
}