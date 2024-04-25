/*
* Paiza ƒŒƒxƒ‹ƒAƒbƒv–â‘èW
* •—Dæ’TõE[‚³—Dæ’Tõƒƒjƒ…[ —Ìˆæ‚ÌŒÂ”
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
void Search(int count, int H, int W, int y, int x);
void Step2();
void MapSearch(const vector<vector<char>>&, vector<vector<bool>>&, int, int, int, int);

int main()
{
	Step2();
}

void Step1()
{
	int H, W, y, x;
	cin >> H >> W >> y >> x;

	Search(0, H, W, y, x);
}

void Search(int count, int H, int W, int y, int x)
{
	if (count == 3)
	{
		cout << to_string(y) + " " + to_string(x) << endl;
		return;
	}

	//ã
	if (0 <= y - 1)
	{
		Search(count + 1, H, W, y - 1, x);
	}

	//‰E
	if (x + 1 < W)
	{
		Search(count + 1, H, W, y, x + 1);
	}

	//‰º
	if (y + 1 < H)
	{
		Search(count + 1, H, W, y + 1, x);
	}

	//¶
	if (0 <= x - 1)
	{
		Search(count + 1, H, W, y, x - 1);
	}

}


const char wall = '#';
const char canThroughSquare = '.';

void Step2()
{
	int H, W;
	cin >> H >> W;
	cin.ignore();
	vector<vector<char>> map(H, vector<char>(W));

	//true = ’TõÏ‚İ,•Ç false:–¢’Tõ
	vector<vector<bool>> searchLogs(H, vector<bool>(W, false));


	for (auto i = 0; i < H; ++i)
	{
		string s;
		getline(cin, s);
		vector<char> c(s.begin(), s.end());
		map[i] = c;
	}

	for (auto i = 0; i < H; ++i)
	{
		for (auto j = 0; j < W; ++j)
		{
			if (map[i][j] == '#')
			{
				searchLogs[i][j] = true;
			}
		}
	}

	int count = 0;
	for (auto i = 0; i < H; ++i)
	{
		for (auto j = 0; j < W; ++j)
		{
			if (map[i][j] == '.' && !searchLogs[i][j])
			{
				MapSearch(map, searchLogs, H, W, i, j);
				++count;
			}
		}
	}
	cout << count;
}

void MapSearch(const vector<vector<char>>& map, vector<vector<bool>>& searchLogs, int H, int W, int y, int x)
{
	searchLogs[y][x] = true;

	//ã
	if (0 <= y - 1 && !searchLogs[y - 1][x])
	{
		MapSearch(map, searchLogs, H, W, y - 1, x);
	}

	//‰E
	if (x + 1 < W && !searchLogs[y][x + 1])
	{
		MapSearch(map, searchLogs, H, W, y, x + 1);
	}

	//‰º
	if (y + 1 < H && !searchLogs[y + 1][x])
	{
		MapSearch(map, searchLogs, H, W, y + 1, x);
	}

	//¶
	if (0 <= x - 1 && !searchLogs[y][x - 1])
	{
		MapSearch(map, searchLogs, H, W, y, x - 1);
	}
}
