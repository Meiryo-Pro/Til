/*
* Paiza レベルアップ問題集
* 幅優先探索・深さ優先探索メニュー 1頂点の移動
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
void Bfs(vector<vector<int>>&, vector<int>&, queue<int>&, const int);
void Dfs(vector<vector<int>>&, vector<int>&, int, const int);
int countUnexplored(const vector<int>&);
void Ans();

int main()
{
	Step2();
	//Ans();
}

void Step1()
{
	int N, X;
	cin >> N >> X;

	vector<vector<int>> tree(N);
	vector<bool> dist(N, false);

	for (auto i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;

		tree[a].emplace_back(b);
		tree[b].emplace_back(a);
	}
	Step1Search(tree, dist, --X);
}

void Step1Search(vector<vector<int>>& tree, vector<bool>& dist, int current)
{
	if (dist[current])
	{
		return;
	}

	cout << current + 1 << endl;
	dist[current] = true;

	sort(tree[current].begin(), tree[current].end());

	for (auto next : tree[current])
	{
		Step1Search(tree, dist, next);
	}
}

void Step2()
{
	int N, X, Y;
	cin >> N >> X >> Y;

	vector<vector<int>> tree(N);
	vector<int> dist(N, -1);

	for (auto i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;

		tree[a].emplace_back(b);
		tree[b].emplace_back(a);
	}

	for (auto& vertexes : tree)
	{
		sort(vertexes.begin(), vertexes.end());
	}

	dist[X - 1] = 1;
	queue<int> que;
	que.push(X - 1);
	Bfs(tree, dist, que, Y - 1);
	int bfsAns = countUnexplored(dist);

	dist = vector<int>(dist.size(), -1);
	Dfs(tree, dist, X - 1, Y - 1);
	int dfsAns = countUnexplored(dist);

	if (bfsAns > dfsAns)
	{
		cout << "bfs" << endl;
	}
	else if (bfsAns < dfsAns)
	{
		cout << "dfs" << endl;
	}
	else
	{
		cout << "same" << endl;
	}
}


void Bfs(vector<vector<int>>& tree, vector<int>& dist, queue<int>& que, const int target)
{
	while (!que.empty())
	{
		int current = que.front();
		que.pop();

		for (auto node : tree[current])
		{
			if (dist[node] == -1)
			{
				dist[node] = dist[current] + 1;

				if (node == target)
				{
					return;
				}

				que.push(node);
			}
		}
	}
}


void Dfs(vector<vector<int>>& tree, vector<int>& dist, int current, const int target)
{
	if (dist[target] != -1)
	{
		return;
	}

	if (dist[current] == -1)
	{
		dist[current] = current + 1;
	}

	sort(tree[current].begin(), tree[current].end());

	for (auto node : tree[current])
	{
		if (dist[node] == -1)
		{
			Dfs(tree, dist, node, target);
		}
	}
}

int countUnexplored(const vector<int>& dist)
{
	int count = 0;
	
	for (auto d : dist)
	{
		if (d == -1)
		{
			++count;
		}
	}
	return count;
}

vector<vector<int> > graph(5000);
vector<bool> dfs_unvisited(5000, true);
vector<bool> bfs_unvisited(5000, true);

int bfs_count = 0, dfs_count = 0;
int y;

void dfs(int now)
{
	dfs_unvisited[now] = false;
	if (dfs_unvisited[y])
	{
		dfs_count++;
	}
	for (int i = 0; i < graph[now].size(); i++)
	{
		if (dfs_unvisited[graph[now][i]])
		{
			dfs(graph[now][i]);
		}
	}
}

void Ans()
{
	int n, x;
	cin >> n >> x >> y;

	x--;
	y--;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(x);

	queue<int> Q;

	Q.push(x);
	bfs_unvisited[x] = false;

	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();

		if (now == y)
		{
			break;
		}
		else
		{
			bfs_count++;
		}

		for (auto next : graph[now])
		{
			if (bfs_unvisited[next])
			{
				bfs_unvisited[next] = false;
				Q.push(next);
			}
		}
	}

	if (bfs_count < dfs_count)
	{
		cout << "bfs" << endl;
	}
	else if (bfs_count == dfs_count)
	{
		cout << "same" << endl;
	}
	else
	{
		cout << "dfs" << endl;
	}
}