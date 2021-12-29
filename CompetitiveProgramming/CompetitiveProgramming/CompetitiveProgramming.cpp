#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	vector<int> nums(N);

	for (auto i = 0; i < N; ++i)
	{
		cin >> nums.at(i);
	}

	bool loop = true;
	int result = 0;
	while (loop)
	{
		for (auto num : nums)
		{
			if (num & 1)
			{
				loop = false;
				break;
			}
		}

		for (auto i = 0; i < N; ++i)
		{
			nums.at(i) = nums.at(i) >> 1;
		}

		if (loop)
		{
			++result;
		}
	}

	cout << result << endl;
}