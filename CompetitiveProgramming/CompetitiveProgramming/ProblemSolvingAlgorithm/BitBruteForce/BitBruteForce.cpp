#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

int main()
{
	/*int N, W;
	cin >> N >> W;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
	}*/

	int N = 5;
	int W = 10;
	vector<int> a{ 1,2,4,5,11 };

	cout << "N:" << N << endl;
	cout << endl;
	for (auto v : a)
	{
		cout << v << ",";
	}
	cout << endl;

	bool exist = false;

	/** 例：N = 5, W = 10, a{1,2,4,5,11}
		00000～11111までの組み合わせを全部試し
		sum=10となる組み合わせが見つかればYes
	*/
	//bitは2^N通りの部分集合全体を動く
	for (int bit = 0; bit < (1 << N); ++bit)
	{
		//部分集合に含まれる要素の和
		int sum = 0;
		for (int i = 0; i < N; ++i)
		{

			//i番目の要素a[i]が部分集合に含まれているか
			if (bit & (1 << i))
			{
				sum += a[i];
				cout << "sum:" << sum << endl;
				cout << "i:" << i << ", bit:" << bitset< (5)>(bit) << ", (1 << i):" << bitset< (5)>((1 << i)) << endl;

			}

		}

		if (sum == W)
		{
			exist = true;
			break;
		}
	}

	if (exist)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}