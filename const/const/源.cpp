#include<iostream>
using namespace std;
int main()
{

	//char* const name = "chen";
	//*name = 'a';
	//cout << name << endl;
	int a = 10;
	int c = 20;
	int const* b = &a;
	b = &c;
	cout << a << endl;
	system("pause");
	return 0;
}
