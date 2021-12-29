#include<iostream>
#include<vector>
#include<string>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::swap;

int FindCount();
int FindSecondMin();
int Difference();
int ShiftOnly();
int SumOfThreeIntegers();
long ManyNumericalFormula();

int main()
{
	//cout << FindCount() << endl;
	//cout << FindSecondMin() << endl;
	//cout << Difference() << endl;
	cout << ShiftOnly() << endl;
}

int FindCount()
{
	int N = 0;
	int target = 0;
	cin >> N >> target;
	vector<int> nums(N);

	for (auto i = 0; i < N; ++i)
	{
		cin >> nums.at(i);
	}

	int count = 0;

	for (auto num : nums)
	{
		if (num == target)
		{
			++count;
		}
	}

	return count;
}

int FindSecondMin()
{
	int N = 0;
	cin >> N;
	vector<int> nums(N);

	for (auto i = 0; i < N; ++i)
	{
		cin >> nums.at(i);
	}

	int firstMin = nums.at(0);
	int secondMin = nums.at(1);

	if (firstMin > secondMin)
	{
		swap(firstMin, secondMin);
	}

	for (auto i = 2; i < nums.size(); ++i)
	{
		if (firstMin > nums.at(i))
		{
			swap(firstMin, secondMin);
			firstMin = nums.at(i);
		}
		else
		{
			if (secondMin > nums.at(i))
			{
				secondMin = nums.at(i);
			}
		}
	}

	return secondMin;
}

int Difference()
{
	int N = 0;
	cin >> N;
	vector<int> nums(N);

	for (auto i = 0; i < N; ++i)
	{
		cin >> nums.at(i);
	}

	int max = nums.at(0);
	int min = nums.at(1);

	if (min > max)
	{
		swap(min, max);
	}

	for (auto i = 2; i < N; i++)
	{
		if (min > nums.at(i))
		{
			min = nums.at(i);
		}
		else if (max < nums.at(i))
		{
			max = nums.at(i);
		}

	}

	return max - min;
}

int ShiftOnly()
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

	return result;
}

int SumOfThreeIntegers()
{
	int K, S = 0;
	cin >> K >> S;
	int sum = 0;

	for (auto X = 0; X < K; X++)
	{
		for (auto Y = 0; Y < K; Y++)
		{
			int Z = S - X - Y;
			if (Z >= 0 && Z <= K)
			{
				++sum;
			}
		}
	}

	return sum;
}

long ManyNumericalFormula()
{
	std::string input;
	vector<int> nums(input.length());

	for (auto i = 0; i < input.length(); ++i)
	{
		nums.at(i) == input[i];
	}

}