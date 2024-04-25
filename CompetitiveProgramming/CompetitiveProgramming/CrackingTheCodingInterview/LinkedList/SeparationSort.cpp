#include <iostream>
#include<list>
using namespace std;

template<typename T>
void Print(const list<T>&);

template<typename T>
void Sort(list<T>&, int);

int main()
{
	list<int> list{ 3,5,8,5,10,5,2,1 };
	Print(list);

	int separateNum = 0;
	cout << "区切りたい数字";
	cin >> separateNum;
	Sort(list, separateNum);
	Print(list);
}

template<typename T>
void Sort(list<T>& list, int separateNum)
{
	auto separateStart = find(list.begin(), list.end(), separateNum);
	auto separateEnd = separateStart;

	for (auto iter = list.begin(); iter != list.end(); ++iter)
	{
		//区切りたい文字より前に大きい数字がある場合末尾に飛ばし
		//文字より後にある場合先頭に飛ばす
		//同値だったらそのまま

		//区切りたい文字より前の場合
		if (iter < separateStart)
		{
			if (*iter > *separateEnd)
			{
				list.emplace_back(*iter);
			}
		}

		//区切りたい数字と同値の場合
		if (iter > separateEnd)
		{

		}
	}
}

	template<typename T>
	void Print(const list<T>&list)
	{
		for (auto i : list)
		{
			cout << i;
		}
		cout << endl;
	}