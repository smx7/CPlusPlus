#include<iostream>
using namespace std;

class A
{
public:
	A(int a1=0)
	{
		a = a1;
		cout << "���๹�캯��" << endl;
	}
	virtual ~A()
	{
		cout << "������������" << endl;
	}
	 /*~A()
	{
		cout << "������������" << endl;
	}*/
private:
	int a;
};
class B: public A
{
public:
	B(int a1=0, int b1=0) :A(a1)
	{
		b = b1;
		cout << "�����๹�캯��" << endl;
	}
	~B()
	{
		cout << "��������������" << endl;
	}
private:
	int b;
};
int main()
{
	A aa(10);
	B bb(3, 4);

	A *p = new B[2];
	delete[] p;

	//B* p2 = (B*)new A[2];
	//delete[] p2;

	/*B* p3 = new B[2];
	delete[] p3;*/

	/*A *p1 = new A[2];
	delete[] p1;*/
	system("pause");
	return 0;
}