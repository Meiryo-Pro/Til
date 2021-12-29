#include <iostream>
#include <vector>
#include<regex>
#include<list>
using namespace std;

void Print(const list<int>&);

int main()
{
	list<int> list{ 1,5,4,7,2,1,1,3,7,6,4,9, };
	Print(list);

	auto searchStart = list.begin();
	auto iter = ++list.begin();

	while (searchStart != list.end())
	{
		while (iter != list.end())
		{
			if (*searchStart == *iter)
			{
				iter = list.erase(iter);
			}
			else
			{
				++iter;
			}

		}
		++searchStart;
	}

	Print(list);
}

void Delete(list<int>& list)
{

}

void Print(const list<int>& list)
{
	for (auto i : list)
	{
		cout << i;
	}
	cout << endl;
}


