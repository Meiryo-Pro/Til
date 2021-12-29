#include <iostream>
#include<list>
using namespace std;

template<typename T>
void Print(const list<T>&);

template<typename T>
bool CheckPalindrome(list<T>&);

int main()
{
	list<char> palindromeList{ 'A','B','C','D','C','B','A' };
	Print(palindromeList);
	cout << CheckPalindrome(palindromeList) << endl;

	list<char>notPalindromeList{ 'A','B','C','A','B','C' };
	cout << CheckPalindrome(notPalindromeList) << endl;


	list<char>PalindromeList2{ 'A','B','C','C','B','A'};
	cout << CheckPalindrome(PalindromeList2) << endl;

}

template<typename T>
bool CheckPalindrome(list<T>& list)
{
	auto left = list.begin();
	auto right = list.end();
	--right;

	auto loopCount = distance(list.begin(), list.end()) / 2;

	for (auto i = 0; i < loopCount; ++i)
	{
		if (*left != *right)
		{
			return false;
		}
		++left;
		--right;
	}
	return true;
}

template<typename T>
void Print(const list<T>& list)
{
	for (auto i : list)
	{
		cout << i;
	}
	cout << endl;
}