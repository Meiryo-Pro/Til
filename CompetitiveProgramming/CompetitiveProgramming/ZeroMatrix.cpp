#include <iostream>
#include <vector>
#include<random>
#include<ctime>

using namespace std;

vector<vector<int>> RandomMatrix(int size);
void PrintMatrix(const vector<vector<int>>&);
vector<pair<int, int>> FindZeroFieldIndex(const vector<vector<int>>&);
vector<vector<int>> Replace(const vector<vector<int>>&, const vector<pair<int, int>>&);

int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> matrix;
	matrix = RandomMatrix(n);
	PrintMatrix(matrix);

	vector<pair<int, int>> indexes;
}

vector<vector<int>> RandomMatrix(int size)
{
	vector<vector<int>> matrix(size,vector<int>(size));
	srand(time(nullptr));

	//for (auto i = 0; i < size; ++i)
	//{
	//	for (auto j = 0; j < size; ++j)
	//	{
	//		int randomNum = rand() % 6 + 1;
	//		if (randomNum % 6 == 0)
	//		{
	//			matrix.at(i).at(j) = 0;
	//		}
	//		else
	//		{
	//			matrix.at(i).at(j) = randomNum;
	//		}
	//	}
	//}

	for (auto row : matrix)
	{
		for (auto column : row)
		{
			int randomNum = rand() % 6 + 1;
			if (randomNum % 6 == 0)
			{
				column = 0;
			}
			else
			{
				column = randomNum;
			}
		}
	}
	return matrix;
}


void PrintMatrix(const vector<vector<int>>& matrix)
{
	for (auto row : matrix)
	{
		for (auto column : row)
		{
			cout << column;
		}
		cout << endl;
	}
}

vector<pair<int, int>> FindZeroFieldIndex(const vector<vector<int>>& matrix)
{
	vector<pair<int, int>> indexes;

	for (auto i = 0; i < matrix.size(); ++i)
	{
		for (auto j = 0; j < matrix.size(); ++j)
		{
			if (matrix.at(i).at(j) == 0)
			{
				indexes.emplace_back(i, j);
			}
		}
	}
	return indexes;
}

vector<vector<int>> Replace(const vector<vector<int>>& matrix, const vector<pair<int, int>>& indexes)
{
	
}