#include <iostream>
#include<forward_list>
using namespace std;

template<typename T>
void Print(const forward_list<T>&);

template<typename T>

int main()
{
	int digit = 0;
	cin >> digit;
	forward_list<int> list;

	for()
	Print(list);
}



template<typename T>
void Print(const forward_list<T>& list)
{
	for (auto i : list)
	{
		cout << i;
	}
	cout << endl;
}