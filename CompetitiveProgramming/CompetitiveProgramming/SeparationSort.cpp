#include <iostream>
#include<list>
using namespace std;

template<typename T>
void Print(const list<T>&);

template<typename T>
void Sort(list<T>&,int);

int main()
{
	list<int> list{ 3,5,8,5,10,5,2,1 };
	Print(list);

	int separateNum = 0;
	cout << "‹æØ‚è‚½‚¢”š";
	cin >> separateNum;
	Sort(list,separateNum);
	Print(list);
}

template<typename T>
void Sort(list<T>& list,int separateNum)
{
	auto separateBack = find(list.begin(),list.end(),separateNum);
	auto separateFront = separateBack;


	for (auto iter = list.begin(); iter != list.end(); ++iter)
	{
		if (*iter < *separateBack)
		{
			swap(*iter, *separateBack);
		}
		else if (*iter > separateNum)
		{
			swap(*iter, *separateFront);
		}
		else
		{
			swap(iter, separateFront);
		}
	}
}

template<typename T>
void Print(const list<T>& list)
{
	for (auto i : list)
	{
		cout << i;
	}
	cout << endl;
}