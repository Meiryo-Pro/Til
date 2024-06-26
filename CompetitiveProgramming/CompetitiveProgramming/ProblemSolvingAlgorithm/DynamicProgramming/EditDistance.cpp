#include<iostream>
#include<vector>
#include<vector>
using namespace std;

template<class T> void chmin(T& a, T b)
{
	if (a > b)
	{
		a = b;
	}
}

const int INF = 1 << 29;

int main()
{
	string S, T;
	cin >> S >> T;

	vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, INF));

	dp[0][0] = 0;

	for (int i = 0; i <= S.size(); ++i)
	{
		for (int j = 0; j <= T.size(); ++j)
		{
			//�ύX����
			if (i > 0 && j > 0)
			{
				if (S[i - 1] == T[j - 1])
				{
					chmin(dp[i][j], dp[i - 1][j - 1]);
				}
				else
				{
					chmin(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}

			//�폜����
			if (i > 0) chmin(dp[i][j], dp[i - 1][j] + 1);

			//�}������
			if (j > 0) chmin(dp[i][j], dp[i][j - 1] + 1);

		}
	}
}