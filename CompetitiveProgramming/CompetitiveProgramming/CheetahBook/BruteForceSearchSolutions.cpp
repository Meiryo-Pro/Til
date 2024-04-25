#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <algorithm>


using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::string;
using std::unordered_map;

int InterestingParty(vector<string>&, vector<string>&);
void ExecInterestingParty();

long long Cryptography(vector<int>&);
void ExecCyrptography();

int main()
{
	ExecCyrptography();
}

void ExecInterestingParty()
{
	vector<string> first = { "fishing", "gardening", "swimming", "fishing" };
	vector<string> second = { "hunting", "fishing", "fishing", "biting" };
	//Returns: 4
	cout << InterestingParty(first, second) << endl;

	first = { "variety", "diversity", "loquacity", "courtesy" };
	second = { "talking", "speaking", "discussion", "meeting" };
	//Returns: 1
	cout << InterestingParty(first, second) << endl;

	first = { "snakes", "programming", "cobra", "monty" };
	second = { "python", "python", "anaconda", "python" };
	//Returns: 3
	cout << InterestingParty(first, second) << endl;

	first = { "t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r",
	"o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i" };

	second = { "n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w",
	"e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y" };
	//Returns:6
	cout << InterestingParty(first, second) << endl;
}


int InterestingParty(vector<string>& first, vector<string>& second)
{
	unordered_map<string, int> wordCount;

	for (auto i = 0; i < first.size(); ++i)
	{
		string s = first.at(i);
		string s2 = second.at(i);

		if (wordCount.find(s) == wordCount.end())
		{
			wordCount.emplace(s, 1);
		}
		else
		{
			++wordCount[s];
		}

		if (wordCount.find(s2) == wordCount.end())
		{
			wordCount.emplace(s2, 1);
		}
		else
		{
			++wordCount[s2];
		}
	}

	int max = 0;
	for (auto iter = wordCount.begin(); iter != wordCount.end(); ++iter)
	{
		if (iter->second > max)
		{
			max = iter->second;
		}
	}

	return max;
}

void ExecCyrptography()
{
	vector<int> nums = { 1,2,3 };
	cout << Cryptography(nums) << endl;
	cout << "“š‚¦:12" << endl;

	nums = { 1,3,2,1,1,3 };
	cout << Cryptography(nums) << endl;
	cout << "“š‚¦:36" << endl;

	nums = { 1000,999,998,997,996,995 };
	cout << Cryptography(nums) << endl;
	cout << "“š‚¦:986074810223904000" << endl;

	nums = { 1,1,1,1 };
	cout << Cryptography(nums) << endl;
	cout << "“š‚¦:2" << endl;
}

long long Cryptography(vector<int>& nums)
{
	int minValIndex = 0;
	int minVal = INT_MAX;

	for (auto i = 0; i < nums.size(); ++i)
	{
		if (nums.at(i) < minVal)
		{
			minVal = nums.at(i);
			minValIndex = i;
		}
	}

	++nums.at(minValIndex);

	long long result = 1;

	for (auto num : nums)
	{
		result *= num;
	}

	return result;
}