#include<iostream>
#include<vector>
#include<string>
#include<bitset>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::swap;

int Tribonacci();
int Tribonacci(int, vector<int>&);
int Count753();
int Count753(int, int);
int Count753Answer();
int Count753Answer(long long, long long, int, long long&);

int main()
{
	//cout << Tribonacci() << endl;
	//cout << Count753() << endl;

}


int Tribonacci()
{
	vector<int> memo;

	int N;
	cin >> N;

	memo.assign(N, -1);
	return Tribonacci(N, memo);
}

int Tribonacci(int N, vector<int>& memo)
{
	if (N == 0) return 0;
	else if (N == 1) return 1;
	else if (N == 2) return 1;

	if (memo.at(N - 1) != -1) return memo.at(N - 1);

	return memo.at(N - 1) = Tribonacci(N - 1, memo) + Tribonacci(N - 2, memo) + Tribonacci(N - 3, memo);
}

int Count753()
{
	int N, count = 0;
	cin >> N;

	if (N < 357)
	{
		return 0;
	}
	else
	{
		return Count753(N, count);
	}
}

int Count753(int N, int count)
{
	if (N == 357)
	{
		return ++count;
	}

	int num = N;
	bool existThree = false;
	bool existFive = false;
	bool existSeven = false;
	bool otherNum = false;

	while (num != 0)
	{
		int result = num % 10;

		switch (result)
		{
			case 3:
				existThree = true;
				break;
			case 5:
				existFive = true;
				break;
			case 7:
				existSeven = true;
				break;
			default:
				otherNum = true;
				break;
		}

		if (otherNum)
		{
			break;
		}

		num /= 10;
	}

	if (existThree && existFive && existSeven && !otherNum)
	{
		return Count753(N - 1, ++count);
	}
	else
	{
		return Count753(N - 1, count);
	}

}

int Count753Answer()
{
	long long N;
	cin >> N;
	long long counter = 0;
	Count753Answer(N, 0, 0, counter);
	cout << counter << endl;
}

int Count753Answer(long long N, long long cur, int use, long long& counter)
{
	if (cur > N) return; // ベースケース
	if (use == 0b111) ++counter; // 答えを増やす

	// 7 を付け加える
	Count753Answer(N, cur * 10 + 7, use | 0b001, counter);

	// 5 を付け加える
	Count753Answer(N, cur * 10 + 5, use | 0b010, counter);

	// 3 を付け加える
	Count753Answer(N, cur * 10 + 3, use | 0b100, counter);
}