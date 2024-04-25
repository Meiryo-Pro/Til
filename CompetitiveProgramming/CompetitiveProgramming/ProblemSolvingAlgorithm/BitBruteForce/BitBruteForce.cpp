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

	/** ��FN = 5, W = 10, a{1,2,4,5,11}
		00000�`11111�܂ł̑g�ݍ��킹��S������
		sum=10�ƂȂ�g�ݍ��킹���������Yes
	*/
	//bit��2^N�ʂ�̕����W���S�̂𓮂�
	for (int bit = 0; bit < (1 << N); ++bit)
	{
		//�����W���Ɋ܂܂��v�f�̘a
		int sum = 0;
		for (int i = 0; i < N; ++i)
		{

			//i�Ԗڂ̗v�fa[i]�������W���Ɋ܂܂�Ă��邩
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