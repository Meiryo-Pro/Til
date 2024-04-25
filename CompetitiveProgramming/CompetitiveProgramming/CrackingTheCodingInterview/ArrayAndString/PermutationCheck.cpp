#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;
bool IsPermutation(const string&, const string&);
bool ImprovedIsSortedWords(const string& source, const string& words);

int main()
{
	string source = "abcdefgh";
	string permutationWords = "hgfedcba";
	string randomWords = "abchdfgn";

	//cout << IsPermutation(source, permutationWords) << endl;
	//cout << IsPermutation(source, randomWords) << endl;

	cout << ImprovedIsSortedWords(source, permutationWords) << endl;
	cout << ImprovedIsSortedWords(source, randomWords) << endl;
}

bool IsPermutation(const string& source, const string& words)
{
	//•¶Žš—ñ‚Ì’·‚³‚ªˆá‚¤‚È‚ç•À‚Ñ‘Ö‚¦‚Å‚Í‚È‚¢
	if (source.length() != words.length())
	{
		return false;
	}

	unordered_map<char, int> map;

	for (auto i = 0; i < source.length(); ++i)
	{
		if (map.find(source[i]) == map.end())
		{
			map.emplace(source[i], 1);
		}
		else
		{
			++map[source[i]];
		}
	}

	for (auto i = 0; i < words.length(); ++i)
	{
		//Œ³‚Ì•¶Žš—ñ‚É–³‚¢•¶Žš‚ªŠÜ‚Ü‚ê‚Ä‚¢‚½‚ç“¯ˆê‚Å‚Í‚È‚¢
		if (map.find(words[i]) == map.end())
		{
			return false;
		}
		else
		{
			++map[words[i]];
		}
	}

	for (auto iter = map.begin(); iter != map.end(); ++iter)
	{
		//“¯‚¶•¶Žš—ñ‚È‚ç‚ÎoŒ»‚·‚é•¶Žš‚Ì”‚Í‹ô”‚Ì‚Í‚¸
		if (iter->second % 2 != 0)
		{
			return false;
		}
	}

	return true;
}

//‰ð–@Œ©‚½
bool ImprovedIsSortedWords(const string& source, const string& words)
{
	//•¶Žš—ñ‚Ì’·‚³‚ªˆá‚¤‚È‚ç•À‚Ñ‘Ö‚¦‚Å‚Í‚È‚¢
	if (source.length() != words.length())
	{
		return false;
	}

	unordered_map<char, int> map;
	for (auto i = 0; i < source.length(); ++i)
	{
		if (map.find(source[i]) == map.end())
		{
			map.emplace(source[i], 1);
		}
		else
		{
			++map[source[i]];
		}
	}



	for (auto i = 0; i < words.length(); ++i)
	{
		//Œ³‚Ì•¶Žš—ñ‚É–³‚¢•¶Žš‚ªŠÜ‚Ü‚ê‚Ä‚¢‚½‚ç“¯ˆê‚Å‚Í‚È‚¢
		if (map.find(words[i]) == map.end())
		{
			return false;
		}
		else
		{
			--map[words[i]];
			if (map[words[i]] < 0)
			{
				return false;
			}
		}
	}

	return true;
}