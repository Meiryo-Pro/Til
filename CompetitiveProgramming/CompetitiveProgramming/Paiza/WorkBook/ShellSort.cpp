/*
* Paiza 問題集 シェルソート
* https://paiza.jp/works/mondai/sort_efficient/sort_efficient__shell
*/
#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

void insertion_sort(vector<int>&, int, int);
void shell_sort(vector<int>&, int, int);

int num_of_move = 0;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> vec;
	vec.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec.at(i);
	}

	int k = 0;
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int groupCount = 0;
		cin >> groupCount;
		shell_sort(vec, vec.size(), groupCount);
	}

}


void insertion_sort(vector<int>& vec, int vecSize, int interval)
{
	for (int i = interval; i < vecSize; ++i)
	{
		// 実装の都合上、A[i] の値が上書きされてしまうことがあるので、予め A[i] の値をコピーしておく 
		int tmp = vec[i];

		// vec[i] の適切な挿入位置を表す変数 j を用意
		int j = i - interval;

		while (j >= 0 && vec[j] > tmp)
		{
			vec[j + interval] = vec[j];
			j -= interval;
			++num_of_move;
		}

		// A[i] を挿入
		vec[j + interval] = tmp;
	}
}


void shell_sort(vector<int>& vec, int vecSize, int groupCount)
{
	num_of_move = 0;

	for (int i = groupCount; i > 0; --i)
	{
		insertion_sort(vec, vecSize, groupCount);
	}
	cout << num_of_move << endl;
}


