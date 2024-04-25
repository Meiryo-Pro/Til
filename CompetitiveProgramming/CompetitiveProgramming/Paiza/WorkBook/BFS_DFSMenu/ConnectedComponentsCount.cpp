/*
* Paiza レベルアップ問題集
* 幅優先探索・深さ優先探索メニュー 連結成分の個数
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
#include<queue>

using namespace std;

void Step1();
void Step1Search(vector<vector<int>>&, vector<bool>&, int);
void Step2();
bool IsBipartiteGraph(vector<vector<int>>&, vector<int>&, int, int);
void Step3();
void Step3Search(const vector<vector<int>>&, vector<int>&, int, int);

int main()
{
	Step3();
}

void Step1()
{
	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<int>> graph(N);
	vector<bool> dist(N, false);

	for (auto i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		--a;
		--b;

		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	Step1Search(graph, dist, X - 1);
}

void Step1Search(vector<vector<int>>& graph, vector<bool>& dist, int current)
{
	if (dist[current])
	{
		return;
	}
	else
	{
		cout << current + 1 << endl;
	}

	dist[current] = true;


	sort(graph[current].begin(), graph[current].end());

	for (auto vertex : graph[current])
	{
		if (!dist[vertex])
		{
			Step1Search(graph, dist, vertex);
		}
	}
}

void Step2()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N);
	vector<bool> dist(N, false);
	vector<int> colors(N, -1);

	for (auto i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		--a;
		--b;

		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	bool isBipartiteGraph = true;

	for (auto i = 0; i < N; ++i)
	{
		if (!isBipartiteGraph)
		{
			break;
		}

		if (colors[i] != -1)
		{
			continue;
		}

		isBipartiteGraph = IsBipartiteGraph(graph, colors, 0, i);
	}

	if (isBipartiteGraph)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}


bool IsBipartiteGraph(vector<vector<int>>& graph, vector<int>& colors, int nextColor, int current)
{
	if (colors[current] == -1)
	{
		colors[current] = nextColor;

		if (nextColor == 0)
		{
			nextColor = 1;
		}
		else
		{
			nextColor = 0;
		}
	}

	for (auto vertex : graph[current])
	{
		if (colors[current] == colors[vertex])
		{
			return false;
		}

		if (colors[vertex] == -1)
		{
			if (!IsBipartiteGraph(graph, colors, nextColor, vertex))
			{
				return false;
			}
		}
	}

	return true;
}


void Step3()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N);
	vector<int> group(N, -1);
	int count = 0;

	for (auto i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		--a;
		--b;

		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}


	for (auto i = 0; i < N; ++i)
	{
		if (group[i] != -1)
		{
			continue;
		}

		Step3Search(graph, group, count, i);
		++count;
	}

	cout << count << endl;
}

void Step3Search(const vector<vector<int>>& graph, vector<int>& group, int count, int current)
{
	if (group[current] != -1)
	{
		return;
	}

	group[current] = count;

	for (auto vertex : graph[current])
	{
		if (group[vertex] == -1)
		{
			Step3Search(graph, group, count, vertex);
		}
	}
}
