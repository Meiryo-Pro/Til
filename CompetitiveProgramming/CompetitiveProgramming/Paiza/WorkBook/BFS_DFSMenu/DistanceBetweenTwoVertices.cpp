/*
* Paiza レベルアップ問題集
* 幅優先探索・深さ優先探索メニュー 2頂点間の距離
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;

void Step1();
void Step2();

int main()
{
	Step2();
}

void Step1()
{
	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<int>> tree(N);
	--X;

	for (auto i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;

		tree[a].emplace_back(b);
		tree[b].emplace_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		sort(tree[i].begin(), tree[i].end());
	}


	vector<int> dist(N, -1);
	dist[X] = 0;

	queue<int> q;
	q.push(X);

	vector<int> ans;
	ans.emplace_back(X);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		vector<int> temp;

		for (auto next : tree[current])
		{
			if (dist[next] == -1)
			{
				dist[next] = dist[current] + 1;
				q.push(next);
				temp.emplace_back(next);
			}
		}
		//sort(temp.begin(), temp.end());
		ans.insert(ans.end(), temp.begin(), temp.end());
	}


	for (auto a : ans)
	{
		cout << ++a << endl;
	}
}


void Step2()
{
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;

	vector<vector<int>> tree(N);
	--X;
	--Y;

	for (auto i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;

		tree[a].emplace_back(b);
		tree[b].emplace_back(a);
	}

	vector<int> dist(N, -1);
	dist[X] = 0;

	queue<int> q;
	q.push(X);

	vector<int> ans;
	ans.emplace_back(X);

	bool existPath = false;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		vector<int> temp;

		if (current == Y)
		{
			break;
		}

		for (auto next : tree[current])
		{
			if (dist[next] == -1)
			{
				dist[next] = dist[current] + 1;
				q.push(next);
			}
		}
	}

	cout << dist[Y] << endl;
}
