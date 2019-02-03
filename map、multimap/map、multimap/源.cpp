#include<iostream>
#include<string>
#include<map>

using namespace std;

template<class K,class V>
void print(map<K,V>& m)
{
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << "--->" << (*it).second << "  ";
	}
	cout << endl;
}
void testmap1()
{
	map<int, string> m1;
	map<int, string> m2{
		{ 4, "four" }, { 2, "two" }, { 3, "three" }, 
		{ 1, "one" }, { 5, "five" }, { 2, "two" }
	};
	map<int, string> m3(m2);
	map<int, string> m4(m2.begin(), m2.end());
	m1 = m2;
	print(m1);
	print(m2);
	print(m3);
	print(m4);

}
void testmap2()
{
	map<int, string> m1{
		{ 4, "four" }, { 2, "two" }, { 3, "three" },
		{ 1, "one" }, { 5, "five" }
	};
	m1[6];
	m1[7] = "seven";
	//m1.at(7);
	print(m1);
}

void testmap3()
{
	map<int, string> m1;
	map<int, string> m2{
		{ 1, "one" }, { 4, "four" }
	};

	m1.insert(pair<int, string>(3, "three"));
	m1.insert(make_pair(2, "two"));
	m1.insert(m1.find(1), make_pair(5, "five"));
	m1.find(6);
	m2.insert(m1.begin(), m1.end());
	print(m1);
	print(m2);


	m1.erase(5);
	m1.erase(m1.find(2));
	print(m1);

	m1.swap(m2);
	print(m1);
	print(m2);
	
}
void testmultimap()
{
	multimap<int, string> m1{
		{ 4, "four" }, { 2, "two" }, { 3, "three" },
		{ 2, "two" }, { 5, "five" }, { 5, "five" }, { 1, "one" }
	};
	multimap<int, string>::iterator it = m1.begin();
	while (it != m1.end())
	{
		cout << (*it).first << "-->" << (*it).second << "  ";
		it++;
	}
	cout << endl;
}
int main()
{
	//testmap1();
	//testmap2();
	//testmap3();
	testmultimap();
	system("pause");
	return 0;
}