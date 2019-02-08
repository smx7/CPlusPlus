#include<iostream>
#include<set>
using namespace std;

template<class T>
void print(set<T>& s)
{
	set<T>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void testset1()
{
	set<int> s1;
	set<int> s2{
		{ 2 }, { 4 }, { 1 }, { 1 },{ 6 }
		, { 3 }, { 5 }, { 4 }
	};
	set<int> s3(s2);
	set<int> s4(s2.begin(), s2.end());
	s1 = s3;
	print(s1);
	print(s2);
	print(s3);
	print(s4);
}
void testset2()
{
	set<int> s1;
	pair<set<int>::iterator, bool> ret;
	int arr[] = { 5, 2, 5, 1, 4, 3 };
	ret = s1.insert(3);
	s1.insert(s1.find(2), 6);
	s1.insert(arr, arr + 6);
	print(s1);
	cout << *(ret.first) << " " << ret.second << endl;

	set<int> s2(s1);
	s1.erase(s1.find(3));
	s1.erase(5);
	print(s1);

	s1.swap(s2);
	print(s1);
	print(s2);

	s1.clear();
	print(s1);

	cout << s2.count(2) << endl;
	
}

void testmultiset()
{
	multiset<int> s
	{ { 3 }, { 4 }, { 2 }, { 2 }, 
	{ 1 }, { 6 }, { 3 }, { 5 } };

	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}
int main()
{

	//testset2();
	testmultiset();
	system("pause");
	return 0;
}