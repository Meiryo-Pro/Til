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

//��ԋ𒼂Ȃ�
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


/*Dictionary�ɓo�^���A�o�^���ɓ����������o����d������Ƃ���*/
