#include<iostream>
#include<vector>
#include<string>
#include<bitset>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::string;

void TotalSalary();
long long TotalSalary(vector<string>);

int main()
{

}

void TotalSalary()
{
	vector<string> s = { "N" };
	cout << TotalSalary(s) << endl;
	cout << "����:1" << endl;


	s = { "NNYN",
		"NNYN",
		"NNNN",
		"NYYN" };

	cout << TotalSalary(s) << endl;
	cout << "����:5" << endl;

	s = { "NNNNNN",
		"YNYNNY",
		"YNNNNY",
		"NNNNNN",
		"YNYNNN",
		"YNNYNN" };
	cout << TotalSalary(s) << endl;
	cout << "����:17" << endl;

	s = { "NYNNYN",
		"NNNNNN",
		"NNNNNN",
		"NNYNNN",
		"NNNNNN",
		"NNNYYN" };

	cout << TotalSalary(s) << endl;
	cout << "����:8" << endl;


	s = { "NNNN",
		"NNNN",
		"NNNN",
		"NNNN" };
	cout << TotalSalary(s) << endl;
	cout << "����:4" << endl;
}

long long TotalSalary(vector<string> relations)
{

}