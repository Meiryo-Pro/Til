/*
* Paiza ƒŒƒxƒ‹ƒAƒbƒv–â‘èW
* •—Dæ’TõE[‚³—Dæ’Tõƒƒjƒ…[ 2 ’¸“_ŠÔ‚ÌÅ’ZŒo˜H
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
void Step3();
void Step4();
void Step5();

int main()
{
	Step5();
}

void Step1()
{
	int N, X;
	cin >> N >> X;

	vector<vector<int>> tree(N);
	X--;

	for (auto i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;

		tree[a - 1].emplace_back(b);
		tree[b - 1].emplace_back(a);
	}

	sort(tree.at(X).begin(), tree.at(X).end());

	for (auto& node : tree[X])
	{
		cout << node << endl;
	}
}

void Step2()
{
	int N, X;
	cin >> N >> X;

	vector<vector<int>> tree(N);
	--X;

	for (auto i = 0; i < N - 1; ++i)
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

	queue<int> vertexes;
	vertexes.push(X);

	vector<int> ans;

	while (!vertexes.empty())
	{
		int current = vertexes.front();
		vertexes.pop();

		if (dist[current] == 3)
		{
			ans.emplace_back(current);
			continue;
		}

		for (auto next : tree[current])
		{
			if (dist[next] == -1)
			{
				dist[next] = dist[current] + 1;
				vertexes.push(next);
			}
		}
	}

	sort(ans.begin(), ans.end());

	for (auto vertex : ans)
	{
		cout << vertex + 1 << endl;
	}
}

void Step3()
{
	int N, X, L;
	cin >> N >> X >> L;

	vector<vector<int>> tree(N);
	--X;

	for (auto i = 0; i < N - 1; ++i)
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

	queue<int> vertexes;
	vertexes.push(X);

	vector<int> ans;

	while (!vertexes.empty())
	{
		int current = vertexes.front();
		vertexes.pop();

		if (dist[current] == L)
		{
			ans.emplace_back(current);
			continue;
		}

		for (auto next : tree[current])
		{
			if (dist[next] == -1)
			{
				dist[next] = dist[current] + 1;
				vertexes.push(next);
			}
		}
	}

	sort(ans.begin(), ans.end());

	for (auto vertex : ans)
	{
		cout << vertex + 1 << endl;
	}
}

void Step4()
{
	int N, X, Y;
	cin >> N >> X >> Y;

	vector<vector<int>> tree(N);
	--X;
	--Y;

	for (auto i = 0; i < N - 1; ++i)
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

	queue<int> vertexes;
	vertexes.push(X);

	while (!vertexes.empty())
	{
		int current = vertexes.front();
		vertexes.pop();

		if (current == Y)
		{
			cout << (dist[current]);
			break;
		}

		for (auto next : tree[current])
		{
			if (dist[next] == -1)
			{
				dist[next] = dist[current] + 1;
				vertexes.push(next);
			}
		}
	}
}

void Step5()
{
	int N, X, Y;
	cin >> N >> X >> Y;

	vector<vector<int>> tree(N);
	--X;
	--Y;

	for (auto i = 0; i < N - 1; ++i)
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

	queue<int> vertexes;
	vertexes.push(X);

	vector<int> memory(N,-1);

	while (!vertexes.empty())
	{
		int current = vertexes.front();
		vertexes.pop();

		if (current == Y)
		{
			break;
		}

		for (auto next : tree[current])
		{
			if (dist[next] == -1)
			{
				dist[next] = dist[current] + 1;
				vertexes.push(next);
				memory[next] = current;
			}
		}
	}

	stack<int> ans;
	int prev = Y;

	while (prev != -1)
	{
		ans.emplace(prev + 1);
		prev = memory[prev];
	}

	while (!ans.empty())
	{
		cout << (ans.top()) << endl;
		ans.pop();
	}
}
