#pragma once
#include<iostream>
using namespace std;
template<class T1,class T2>
class Data
{
public:
	Data();
private:

};
template<class T1, class T2>
Data<T1, T2>::Data()
{
	cout << "<T1, T2>" << endl;
}

template<>			//全特化 
class Data<int,int>
{
public:
	Data();
private:

};  
Data<int, int>::Data()  //全特化后定义成员函数不需要模板形参
{
	cout << "<int, int>" << endl;
}

template<class T2>    //偏特化
class Data<int,T2>
{
public:
	Data();
private:

};
template<class T2>
Data<int, T2>::Data()
{
	cout << "<int, T2>" << endl;
}

template<class T1,class T2>    //偏特化 特化两个参数为指针类型
class Data<T1*, T2*>
{
public:
	Data();
private:

};
template<class T1, class T2>
Data<T1*, T2*>::Data()
{
	cout << "<T1*, T2*>" << endl;
}

template<class T1, class T2>    //偏特化 特化两个参数为引用
class Data<T1&, T2&>
{
public:
	Data();
private:

};
template<class T1, class T2>
Data<T1&, T2&>::Data()
{
	cout << "<T1&, T2&>" << endl;
}
void Test()
{
	Data<char, int> d1;
	Data<int, int> d2;
	Data<int, char> d3;
	Data<int*, int*> d4;
	Data<int&, int&> d5;
	Data<int*, string> d6;
}