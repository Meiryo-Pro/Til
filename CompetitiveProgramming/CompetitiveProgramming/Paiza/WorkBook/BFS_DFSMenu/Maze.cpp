/*
* Paiza レベルアップ問題集
* 幅優先探索・深さ優先探索メニュー 迷路
*/

#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include <string>
#include<unordered_map>
#include<queue>

using namespace std;

void PrintMaze(const vector<vector<char>>&);
void Step1();
void Step2();
void MoveAreaSearch(vector<vector<char>>&, int, int, int, int, int);
vector<vector<char>> CreateMaze(int, int, int, int);
void Step3();
bool IsExplored(const vector <vector<int>>&, const int, const int);
void Step4();
bool CanThrough(const char, const int);
void Step5();
void Step6();

int main()
{
	Step6();
}

void Step1()
{
	int H, W;
	cin >> H >> W;

	vector<vector<char>> maze(H, vector<char>(W));

	for (auto& record : maze)
	{
		for (auto& cell : record)
		{
			cell = '.';
		}
	}

	int y, x;
	cin >> y >> x;

	maze[y][x] = '*';


	//上
	if (y - 1 >= 0)
	{
		maze[y - 1][x] = '*';
	}

	//下
	if (y + 1 < H)
	{
		maze[y + 1][x] = '*';
	}

	//右
	if (x + 1 < W)
	{
		maze[y][x + 1] = '*';
	}

	//左
	if (x - 1 >= 0)
	{
		maze[y][x - 1] = '*';
	}

	for (auto& record : maze)
	{
		for (auto& cell : record)
		{
			cout << cell;
		}
		cout << endl;
	}
}

void Step2()
{
	int H, W;
	cin >> H >> W;

	int y, x;
	cin >> y >> x;

	vector<vector<char>> maze = CreateMaze(H, W, y, x);

	for (auto i = 1; i <= 3; ++i)
	{
		MoveAreaSearch(maze, H, W, y, x, 1);
	}

	PrintMaze(maze);
}

void Step3()
{
	int H, W, N;
	cin >> H >> W >> N;

	int y, x;
	cin >> y >> x;

	vector<vector<char>> maze(H, vector<char>(W, '.'));
	maze[y][x] = '*';

	vector<vector<int>> dist(H, vector<int>(W, -1));
	dist[y][x] = 0;

	queue<pair<int, int>> destinations;
	destinations.push({ y, x });


	while (!destinations.empty())
	{
		auto& [y, x] = destinations.front();
		destinations.pop();

		if (dist[y][x] == N)
		{
			continue;
		}

		//上
		if (y - 1 >= 0)
		{
			if (!IsExplored(dist, y - 1, x))
			{
				maze[y - 1][x] = '*';
				dist[y - 1][x] = dist[y][x] + 1;
				destinations.push({ y - 1, x });
			}
		}

		//下
		if (y + 1 < H)
		{
			if (!IsExplored(dist, y + 1, x))
			{
				maze[y + 1][x] = '*';
				dist[y + 1][x] = dist[y][x] + 1;
				destinations.push({ y + 1, x });
			}
		}

		//右
		if (x + 1 < W)
		{
			if (!IsExplored(dist, y, x + 1))
			{
				maze[y][x + 1] = '*';
				dist[y][x + 1] = dist[y][x] + 1;
				destinations.push({ y, x + 1 });
			}
		}

		//左
		if (x - 1 >= 0)
		{
			if (!IsExplored(dist, y, x - 1))
			{
				maze[y][x - 1] = '*';
				dist[y][x - 1] = dist[y][x] + 1;
				destinations.push({ y, x - 1 });
			}
		}
	}
	PrintMaze(maze);
}

//クラスにまとめて引数を減らしたほうが良いが使い捨てなのでこれで
void MoveAreaSearch(vector<vector<char>>& maze, int H, int W, int y, int x, int count)
{
	if (count > 3)
	{
		return;
	}

	//上
	if (y - 1 >= 0)
	{
		maze[y - 1][x] = '*';
	}

	//下
	if (y + 1 < H)
	{
		maze[y + 1][x] = '*';
	}

	//右
	if (x + 1 < W)
	{
		maze[y][x + 1] = '*';
	}

	//左
	if (x - 1 >= 0)
	{
		maze[y][x - 1] = '*';
	}

	++count;

	if (y - 1 >= 0)
	{
		MoveAreaSearch(maze, H, W, y - 1, x, count);
	}

	if (y + 1 < H)
	{
		MoveAreaSearch(maze, H, W, y + 1, x, count);
	}

	if (x - 1 >= 0)
	{
		MoveAreaSearch(maze, H, W, y, x - 1, count);
	}

	if (x + 1 < W)
	{
		MoveAreaSearch(maze, H, W, y, x + 1, count);
	}
}

vector<vector<char>> CreateMaze(int height, int width, int initPosY, int initPosX)
{
	vector<vector<char>> maze(height, vector<char>(width));

	for (auto& record : maze)
	{
		for (auto& cell : record)
		{
			cell = '.';
		}
	}

	maze[initPosY][initPosX] = '*';

	return maze;
}

bool IsExplored(const vector <vector<int>>& dist, const int y, const int x)
{
	return dist[y][x] != -1;
}

void Step4()
{
	int H, W, N;
	cin >> H >> W >> N;

	int y, x;
	cin >> y >> x;
	cin.ignore();

	vector<vector<char>> maze(H, vector<char>(W));

	for (auto i = 0; i < H; ++i)
	{
		string s;
		getline(cin, s);

		vector<char> c(s.begin(), s.end());
		maze[i] = c;
	}

	maze[y][x] = '*';

	vector<vector<int>> dist(H, vector<int>(W, -1));
	dist[y][x] = 0;

	queue<pair<int, int>> destinations;
	destinations.push({ y, x });


	while (!destinations.empty())
	{
		auto [y, x] = destinations.front();
		destinations.pop();

		if (dist[y][x] == N)
		{
			continue;
		}

		//上
		if (y - 1 >= 0)
		{
			if (CanThrough(maze[y - 1][x], dist[y - 1][x]))
			{
				maze[y - 1][x] = '*';
				dist[y - 1][x] = dist[y][x] + 1;
				destinations.push({ y - 1, x });
			}
		}

		//下
		if (y + 1 < H)
		{
			if (CanThrough(maze[y + 1][x], dist[y + 1][x]))
			{
				maze[y + 1][x] = '*';
				dist[y + 1][x] = dist[y][x] + 1;
				destinations.push({ y + 1, x });
			}
		}

		//右
		if (x + 1 < W)
		{
			if (CanThrough(maze[y][x + 1], dist[y][x + 1]))
			{
				maze[y][x + 1] = '*';
				dist[y][x + 1] = dist[y][x] + 1;
				destinations.push({ y, x + 1 });
			}
		}

		//左
		if (x - 1 >= 0)
		{
			if (CanThrough(maze[y][x - 1], dist[y][x - 1]))
			{
				maze[y][x - 1] = '*';
				dist[y][x - 1] = dist[y][x] + 1;
				destinations.push({ y, x - 1 });
			}
		}
	}
	PrintMaze(maze);
}

void Step5()
{
	int H, W;
	cin >> H >> W;

	int sy, sx;
	cin >> sy >> sx;

	int gy, gx;
	cin >> gy >> gx;
	cin.ignore();

	vector<vector<char>> maze(H, vector<char>(W));

	for (auto i = 0; i < H; ++i)
	{
		string s;
		getline(cin, s);

		vector<char> c(s.begin(), s.end());
		maze[i] = c;
	}

	vector<vector<int>> dist(H, vector<int>(W, -1));
	dist[sy][sx] = 0;

	queue<pair<int, int>> destinations;
	destinations.push({ sy, sx });

	bool canGoal = false;

	while (!destinations.empty())
	{
		auto [y, x] = destinations.front();
		destinations.pop();

		if (y == gy && x == gx)
		{
			canGoal = true;
			break;
		}

		//上
		if (y - 1 >= 0)
		{
			if (CanThrough(maze[y - 1][x], dist[y - 1][x]))
			{
				dist[y - 1][x] = dist[y][x] + 1;
				destinations.push({ y - 1, x });
			}
		}

		//下
		if (y + 1 < H)
		{
			if (CanThrough(maze[y + 1][x], dist[y + 1][x]))
			{
				dist[y + 1][x] = dist[y][x] + 1;
				destinations.push({ y + 1, x });
			}
		}

		//右
		if (x + 1 < W)
		{
			if (CanThrough(maze[y][x + 1], dist[y][x + 1]))
			{
				dist[y][x + 1] = dist[y][x] + 1;
				destinations.push({ y, x + 1 });
			}
		}

		//左
		if (x - 1 >= 0)
		{
			if (CanThrough(maze[y][x - 1], dist[y][x - 1]))
			{
				dist[y][x - 1] = dist[y][x] + 1;
				destinations.push({ y, x - 1 });
			}
		}
	}

	cout << (canGoal ? "Yes" : "No") << endl;
}

void Step6()
{
	int H, W;
	cin >> H >> W;

	int sy, sx;
	cin >> sy >> sx;

	int gy, gx;
	cin >> gy >> gx;
	cin.ignore();

	vector<vector<char>> maze(H, vector<char>(W));

	for (auto i = 0; i < H; ++i)
	{
		string s;
		getline(cin, s);

		vector<char> c(s.begin(), s.end());
		maze[i] = c;
	}

	vector<vector<int>> dist(H, vector<int>(W, -1));
	dist[sy][sx] = 0;

	queue<pair<int, int>> destinations;
	destinations.push({ sy, sx });

	bool canGoal = false;

	while (!destinations.empty())
	{
		auto [y, x] = destinations.front();
		destinations.pop();

		if (y == gy && x == gx)
		{
			canGoal = true;
			break;
		}

		//上
		if (y - 1 >= 0)
		{
			if (CanThrough(maze[y - 1][x], dist[y - 1][x]))
			{
				dist[y - 1][x] = dist[y][x] + 1;
				destinations.push({ y - 1, x });
			}
		}

		//下
		if (y + 1 < H)
		{
			if (CanThrough(maze[y + 1][x], dist[y + 1][x]))
			{
				dist[y + 1][x] = dist[y][x] + 1;
				destinations.push({ y + 1, x });
			}
		}

		//右
		if (x + 1 < W)
		{
			if (CanThrough(maze[y][x + 1], dist[y][x + 1]))
			{
				dist[y][x + 1] = dist[y][x] + 1;
				destinations.push({ y, x + 1 });
			}
		}

		//左
		if (x - 1 >= 0)
		{
			if (CanThrough(maze[y][x - 1], dist[y][x - 1]))
			{
				dist[y][x - 1] = dist[y][x] + 1;
				destinations.push({ y, x - 1 });
			}
		}
	}

	if (canGoal)
	{
		cout << dist[gy][gx];
	}
	else
	{
		cout << "No";
	}
}

bool CanThrough(const char square, const int dist)
{
	if (square == '.' && dist == -1)
	{
		return true;
	}

	return false;
}

void PrintMaze(const vector<vector<char>>& maze)
{
	for (auto& record : maze)
	{
		for (auto& cell : record)
		{
			cout << cell;
		}
		cout << endl;
	}
}