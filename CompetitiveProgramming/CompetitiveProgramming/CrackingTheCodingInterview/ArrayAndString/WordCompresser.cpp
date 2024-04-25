#include <iostream>
#include <vector>
#include<unordered_map>
#include <string>
using namespace std;

string Compress(const string&);
void Print(const string&, const string&);

int main()
{
	string input = "aabcccccaaa";
	string compressed = Compress(input);
	Print(input, compressed);

	input = "abcd";
	compressed = Compress(input);
	Print(input, compressed);
}

string Compress(const string& input)
{
	pair<char, int> current{ input[0],1 };
	string result;

	for (int i = 1; i < input.length(); ++i)
	{
		if (current.first == input[i])
		{
			++current.second;
		}
		else
		{
			result += current.first + to_string(current.second);
			current.first = input[i];
			current.second = 1;
		}
	}

	result += current.first + to_string(current.second);

	return result;
}

void Print(const string& input, const string& compressed)
{
	if (input.length() <= compressed.length())
	{
		cout << input << endl;
	}
	else
	{
		cout << compressed << endl;
	}
}