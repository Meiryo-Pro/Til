#include <iostream>
#include <vector>

using namespace std;
bool CheckDeplicate(string);

int main()
{
	string noDeplicateWord = "abcdefgh";
	string DeplicateWord = "abccdeffgh";

	cout << CheckDeplicate(noDeplicateWord) << endl;
	cout << CheckDeplicate(DeplicateWord) << endl;
}

//ˆê”Ô‹ð’¼‚È‚Ì
bool CheckDeplicate(const string s)
{
	for (auto i = 0; i<s.length(); ++i){
		for (auto j = 0; j < s.length(); j++)
		{
			if (j == i)
			{
				continue;
			}

			if (s[i] == s[j])
			{
				return true;
			}
		}
	}

	return false;
}


/*Dictionary‚É“o˜^‚µA“o˜^’†‚É“¯‚¶•¶Žš‚ªo‚½‚çd•¡‚ ‚è‚Æ‚·‚é*/
