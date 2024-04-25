#include <iostream>
#include <vector>
#include<regex>

using namespace std;

string Replace(string, int);

int main()
{
	cout << Replace("Mr John Smith", 13) << endl;
}

string Replace(string input, int length)
{
	return regex_replace(input, regex(R"(\s)"), "%20");
}
