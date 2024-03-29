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
	//文字列の長さが違うなら並び替えではない
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
		//元の文字列に無い文字が含まれていたら同一ではない
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
		//同じ文字列ならば出現する文字の数は偶数のはず
		if (iter->second % 2 != 0)
		{
			return false;
		}
	}

	return true;
}

//解法見た
bool ImprovedIsSortedWords(const string& source, const string& words)
{
	//文字列の長さが違うなら並び替えではない
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
		//元の文字列に無い文字が含まれていたら同一ではない
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