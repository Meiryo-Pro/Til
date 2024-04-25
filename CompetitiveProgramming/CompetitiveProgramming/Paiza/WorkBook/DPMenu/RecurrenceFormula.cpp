#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

void Step4();
void Step5();
int Step5(int);
void Step6();
int Step6(vector<int>&, int);

int main()
{
	//Step4();
	//Step5();
	Step6();
}

void Step4()
{
	int x, d1, d2;
	cin >> x >> d1 >> d2;
	int q;
	cin >> q;

	vector<int> input;
	input.reserve(q);

	unordered_map<int, int> result;
	result.reserve(q);
	result.emplace(1, x);

	int max = 0;

	for (auto i = 0; i < q; ++i)
	{
		int k;
		cin >> k;
		input.emplace_back(k);
		result.emplace(k, 0);

		if (max < k)
		{
			max = k;
		}
	}

	int a = x;
	for (auto i = 2; i <= max; ++i)
	{
		if (i % 2 == 0)
		{
			a += d2;
		}
		else
		{
			a += d1;
		}

		if (result.find(i) != result.end())
		{
			result.at(i) = a;
		}
	}

	for (auto i = 0; i < q; ++i)
	{
		cout << result.at(input.at(i)) << endl;
	}
}

void Step5()
{
	int k;
	cin >> k;

	cout << Step5(k) << endl;
}

int Step5(int k)
{
	if (k == 1) return 1;
	if (k == 2) return 1;

	return Step5(k - 2) + Step5(k - 1);
}

void Step6()
{
	int q;
	cin >> q;

	vector<int> k;

	int max = 0;
	for (auto i = 0; i < q; ++i)
	{
		int temp;
		cin >> temp;
		k.emplace_back(temp);
		if (max < temp)
		{
			max = temp;
		}
	}

	vector<int> a;
	a.assign(max, -1);
	a.at(0) = 1;
	a.at(1) = 1;
	Step6(a, max);

	for (auto i = 0; i < q; ++i)
	{
		cout << a.at(k.at(i)-1) << endl;
	}
}

int Step6(vector<int>& a, int k)
{
	if (k == 1 || k == 2) return 1;

	if (a.at(k - 1) != -1)
	{
		return a.at(k - 1);
	}

	return a.at(k - 1) = Step6(a, k - 2) + Step6(a, k - 1);
}