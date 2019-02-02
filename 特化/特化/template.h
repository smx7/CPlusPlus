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

template<>			//ȫ�ػ� 
class Data<int,int>
{
public:
	Data();
private:

};  
Data<int, int>::Data()  //ȫ�ػ������Ա��������Ҫģ���β�
{
	cout << "<int, int>" << endl;
}

template<class T2>    //ƫ�ػ�
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

template<class T1,class T2>    //ƫ�ػ� �ػ���������Ϊָ������
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

template<class T1, class T2>    //ƫ�ػ� �ػ���������Ϊ����
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