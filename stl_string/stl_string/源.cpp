#include<iostream>
#include<string>
using namespace std;
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	cout << "capacity changed: " << sz << '\n';
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void TestPushBack_P()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();

	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';		}
	}
}
int main()
{
	//int a = 0;
	//cout << typeid(a).name() << endl;

	//int array[] = { 1, 2, 3, 4, 5 };
	//for ( auto &e : array)
	//{
	//	e *= 2;
	//	cout << e << " ";
	//}
	//cout << endl;
	//string s2 = "world";//构造临时对象 拷贝构造 编译器优化

	//TestPushBack();
	//TestPushBack_P();

	string s = "hello";
	cout << s.capacity() << endl;
	s.reserve(40);
	cout << s << endl;
	cout << s.capacity() << endl;
	
	system("pause");
	return 0;

}