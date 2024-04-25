#include<iostream>
#include<vector>
#include<string>
#include<bitset>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::swap;

const long long INF = 1LL << 60;

int main()
{
	int N;
	cin >> N;
	vector<long long> h(N);
	for (int i = 0; i < N; ++i) cin >> h[i];

	vector<long long>dp(N, INF);

	dp[0] = 0;

	for (int i = 1; i < N; ++i)
	{
		if (i == 1)
		{
			dp[i] = abs(h[i] - h[i - 1]);
		}
		else
		{
			dp[i] = std::min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
		}
	}

	cout << dp[N - 1] << endl;
}