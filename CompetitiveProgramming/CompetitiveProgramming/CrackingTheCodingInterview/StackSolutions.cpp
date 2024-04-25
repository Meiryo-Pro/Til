#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<stack>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::stack;

int Min();
int Sort();

int Main()
{

}

int Min()
{
	stack<int> nums;
	vector<int> vec{ 8,4,7,5,2,6 };

	auto min = INT_MAX;

	for (auto num : vec)
	{
		if (min > num)
		{
			min = num;
		}
		nums.push(num);
	}

	return min;
}

int Sort()
{
	stack<int> nums;
	stack<int> temp;

	vector<int> vec{ 8,4,7,5,2,6 };
	
	for (auto num : vec)
	{
		nums.push(num);
	}

	auto max = INT_MIN;

	//1”Ô‘å‚«‚¢‚Ì‚ğ‘I‚ñ‚Åpush‚ğl‚¦‚½‚¯‚Çd‚»‚¤
	if (temp.empty())
	{
		
	}
}