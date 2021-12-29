#include <iostream>
#include<forward_list>
using namespace std;

void Print(const forward_list<int>&);
int Search(const forward_list<int>&, const int);

int main()
{
	forward_list<int> list{ 1,8,4,5,7,9,10 };
	Print(list);
	cout << Search(list, 5) << endl;
}

int Search(const forward_list<int>& list, const int target)
{
	int targetIndex = 0;
	for (auto v : list)
	{
		if (v == target)
		{
			return distance(list.begin(), list.end()) - targetIndex;
		}
		++targetIndex;
	}
}

void Print(const forward_list<int>& list)
{
	for (auto i : list)
	{
		cout << i;
	}
	cout << endl;
}