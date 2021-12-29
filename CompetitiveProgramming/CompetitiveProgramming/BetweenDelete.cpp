#include <iostream>
#include<forward_list>
using namespace std;

template<typename T>
void Print(const forward_list<T>&);

template<typename T>
void Delete(forward_list<T>&);

int main()
{
	forward_list<char> list{ 'a','b','c','d','e','f' };
	Print(list);
	Delete(list);
	Print(list);
}

template<typename T>
void Delete(forward_list<T>& list)
{
	auto deleteIndex = distance(list.begin(), list.end()) / 2 - 1;
	auto iter = list.begin();

	for (auto i = 0; i <= deleteIndex; ++i)
	{
		++iter;
		if (i == deleteIndex)
		{
			list.remove(*iter);
		}
	}
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