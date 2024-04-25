#include <iostream>
#include<cstdlib>
#include<unordered_map>

using namespace std;

bool CanConvert(string, string);
void Emplace(const string& ,unordered_map<char,int>&);

int main()
{
	//true
	cout << CanConvert("pale", "ple") << endl;
	cout << CanConvert("pales", "pale") << endl;
	cout << CanConvert("pale", "bale") << endl;
	cout << CanConvert("pppale", "ppale")<< endl;
	
	//false
	cout << CanConvert("pale", "bake") << endl;
	cout << CanConvert("pale", "pppale") << endl;
}

bool CanConvert(const string before, const string after)
{
	int differentLength = before.length() - after.length();

	//ï∂éöóÒÇÃí∑Ç≥ÇÃç∑Ç™2à»è„Ç≈Ç†ÇÍÇŒfalse
	if (abs(differentLength) >= 2)
	{
		return false;
	}

	unordered_map<char, int> map;
	Emplace(before, map);
	Emplace(after, map);

	int count = 0;
	for (auto iter = map.begin(); iter != map.end(); ++iter)
	{
		if (iter->second % 2 != 0)
		{
			++count;

			/*
			pale bale
			p = 1,b = 1,a = 2, l = 2, e = 2
			count = 2 
			true
			
			pale bake
			p = 1, a = 2, l = 1, e = 2, k = 1
			count = 3 
			false
			*/
			if (count >= 3)
			{
				return false;
			}
		}
	}

	return true;
}

void Emplace(const string& word, unordered_map<char, int>& map)
{
	for (auto c : word)
	{
		if (map.find(c) == map.end())
		{
			map.emplace(c, 1);
		}
		else
		{
			++map[c];
		}
	}
}

//substringÇ≈Ç‘Ç¡Ç±î≤Ç≠ÅH