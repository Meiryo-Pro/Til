#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

void Step1();
void Step2();

int main()
{
	//Step1();
}

void Step1()
{
	int n;
	cin >> n;
	vector<int> result;
	result.emplace_back(1);

	for (auto i = 1; i <= n; ++i)
	{
		result.emplace_back(0);

		if (i >= 1)
		{
			result.at(i) = result.at(i) + result.at(i - 1);
		}

		if (i >= 2)
		{
			result.at(i) = result.at(i) + result.at(i - 2);
		}
	}

	cout << result.at(n) << endl;
}

void Step2()
{
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> result;


}