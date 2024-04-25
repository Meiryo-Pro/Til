#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include <string>

using namespace std;

enum class Winner
{
	None,
	Paiza,
	Erik
};

void Step1();
void Step2();
string MakeResult(const vector<int>&);
void Step3();
void Step4();
void Step5();
void DeleteNode(map<int, vector<int>>&);
void Step6();
Winner ChangeWinner(Winner);
bool IsLeaf(size_t);

int main()
{
	Step6();
}

void Step1()
{
	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	int a, b;
	while (cin >> a >> b)
	{
		matrix[a - 1][b - 1] = 1;
		matrix[b - 1][a - 1] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j != n - 1)
			{
				cout << matrix[i][j] << " ";
			}
			else
			{
				cout << matrix[i][j];
			}
		}
		cout << endl;
	}
}

void Step2()
{
	int n;
	cin >> n;
	map<int, vector<int>> adjacencyList;

	int a, b;
	while (cin >> a >> b)
	{
		adjacencyList[a].emplace_back(b);
		adjacencyList[b].emplace_back(a);
	}

	for (auto& list : adjacencyList)
	{
		cout << MakeResult(list.second) << endl;
	}
}

string MakeResult(const vector<int>& list)
{
	string result;
	vector<int> listCopy = { list.begin(),list.end() };
	sort(listCopy.begin(), listCopy.end());

	for (int i = 0; i < (int)listCopy.size(); ++i)
	{
		result += to_string(listCopy[i]);

		if (i != listCopy.size() - 1)
		{
			result += " ";
		}
	}

	return result;
}

void Step3()
{
	int n, k;
	cin >> n >> k;
	map<int, vector<int>> adjacencyList;
	vector<string> ansList;

	for (auto i = 0; i < n - 1; ++i)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;

		adjacencyList[a].emplace_back(b);
		adjacencyList[b].emplace_back(a);
	}

	for (auto i = 0; i < k; ++i)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;
		if (adjacencyList.find(a) != adjacencyList.end())
		{
			auto target = find(adjacencyList[a].begin(), adjacencyList[a].end(), b);
			if (target != adjacencyList[a].end())
			{
				ansList.emplace_back("YES");
			}
			else
			{
				ansList.emplace_back("NO");
			}
		}
		else
		{
			ansList.emplace_back("NO");
		}
	}

	for (auto& a : ansList)
	{
		cout << a << endl;
	}

}

void Step4()
{
	int n;
	cin >> n;

	map<int, vector<int>> adjacencyList;

	int a = 0;
	int b = 0;

	while (cin >> a >> b)
	{
		adjacencyList[a].emplace_back(b);
		adjacencyList[b].emplace_back(a);
	}

	vector<string> ansList;
	for (auto i = 1; i <= n; ++i)
	{
		if (adjacencyList[i].size() == 1)
		{
			ansList.emplace_back(to_string(i));
		}
	}

	for (auto& a : ansList)
	{
		cout << a << endl;
	}

}

void Step5()
{
	int n;
	cin >> n;

	map<int, vector<int>> adjacencyList;

	int a = 0;
	int b = 0;

	while (cin >> a >> b)
	{
		adjacencyList[a].emplace_back(b);
		adjacencyList[b].emplace_back(a);
	}

	DeleteNode(adjacencyList);

	for (auto& ans : adjacencyList)
	{
		cout << ans.first << endl;
	}
}

void DeleteNode(map<int, vector<int>>& adjacencyList)
{
	int n = (int)adjacencyList.size();

	if (n <= 2)
	{
		return;
	}

	vector<pair<int, int>> deleteTargetNodes;

	//削除する葉を探す
	for (auto& record : adjacencyList)
	{
		if (record.second.size() == 1)
		{
			deleteTargetNodes.emplace_back(record.first, record.second.front());
		}
	}

	for (auto& node : deleteTargetNodes)
	{
		//葉を木から切り離す
		auto targetItr = find(adjacencyList[node.second].cbegin(), adjacencyList[node.second].cend(), node.first);
		adjacencyList[node.second].erase(targetItr);

		//葉を削除
		adjacencyList.erase(node.first);
	}


	DeleteNode(adjacencyList);
}

void Step6()
{
	int n;
	cin >> n;
	vector<vector<int>> adjacencyList(n, vector<int>(n));
	vector<vector<int>> drewList(n, vector<int>(n));

	//初期化
	for (auto i = 0; i < n; ++i)
	{
		for (auto j = 0; j < n; ++j)
		{
			adjacencyList[i][j] = 0;
			drewList[i][j] = 0;
		}
	}

	int a = 0;
	int b = 0;

	while (cin >> a >> b)
	{
		--a;
		--b;

		adjacencyList[a][b] = 1;
		adjacencyList[b][a] = 1;
	}

	Winner winner = Winner::None;

	for (auto i = 0; i < n; ++i)
	{
		for (auto j = 0; j < n; ++j)
		{
			if (i == j)
			{
				continue;
			}

			//辺を選ぶ
			if (adjacencyList[i][j] > 0)
			{
				for (auto k = 0; k < n; ++k)
				{
					if (i == k)
					{
						continue;
					}

					if (adjacencyList[j][k] > 0)
					{
						if (drewList[i][k] == 0 && drewList[k][i] == 0)
						{
							//線を繋ぐ
							if (adjacencyList[i][k] == 0 && adjacencyList[k][i] == 0)
							{
								drewList[i][k] = 1;
								drewList[k][i] = 1;
								winner = ChangeWinner(winner);
							}
						}
					}
				}
			}
		}

	}


	////マージして出力
	//for (auto i = 0; i < n; ++i)
	//{
	//	for (auto j = 0; j < n; ++j)
	//	{
	//		if (drewList[i][j] == 1)
	//		{
	//			adjacencyList[i][j] = 1;
	//		}
	//	}
	//}

	//for (auto& record : adjacencyList)
	//{
	//	for (auto& cell : record)
	//	{
	//		cout << cell << " |";
	//	}
	//	cout << endl;
	//}


	if (winner == Winner::Paiza)
	{
		cout << "paiza" << endl;
	}
	else
	{
		cout << "erik" << endl;
	}

}

Winner ChangeWinner(Winner winner)
{
	switch (winner)
	{
		case Winner::None:
			return Winner::Paiza;

		case Winner::Paiza:
			return Winner::Erik;

		case Winner::Erik:
			return Winner::Paiza;
	}
}