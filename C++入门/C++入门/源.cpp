#include<iostream>
using namespace std;

////һ�������ռ�
//namespace N1
//{
//	int a = 10;
//	int b = 20;
//	int c = a + b;
//	namespace N2
//	{
//		int d = 40;
//	}
//}
//using N1::a;
//using namespace N1;
//int main()
//{
//	cout << N1::c << endl;
//	cout << b << endl;
//	cout << a << endl;
//}

//����ȱʡ����
//void TestFunc(int a = 0,int b=0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	TestFunc(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	TestFunc(10); // ����ʱ��ʹ��ָ����ʵ��
//}
//// ��������
//
//namespace N1
//{
//	int add(int a, int b)
//	{
//		return a + b;
//	}
//	double add(double a, double b)
//	{
//		return a + b;
//	}
//}
//using namespace N1;
//int main()
//{
//	cout << add(1, 2) << endl;
//	cout << add(1.1, 2.2) << endl;
//}

// �ġ�����

//void TestRef()
//{
//	int a = 10;
//	int& ra = a;//<====������������
//
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//}
//int main()
//{
//	TestRef();
//}
//int c = 0;
//int& Add(int a, int b)
//{
//	c = a + b;
//	return a;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

// auto
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
//	return 0;
//}
//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	return 0;
//}

//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (auto& e : array)
//		e *= 2;
//
//	for (auto e : array)
//		cout << e << " ";
//
//	cout << endl;
//	for (auto e : array)
//	{
//		e = 0;
//	}
//	for (auto e : array)
//		cout << e << " ";
//}
//int main()
//{
//	TestFor();
//	return 0;
//}

// nullptr

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f((int*)NULL);
//	return 0;
//}

int main()
{
	cout << sizeof(nullptr) << endl;
	cout << sizeof((void*)0) << endl;
	return 0;
}