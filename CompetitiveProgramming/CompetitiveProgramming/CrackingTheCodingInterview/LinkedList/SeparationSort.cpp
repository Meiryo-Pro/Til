#include <iostream>
#include<list>
using namespace std;

template<typename T>
void Print(const list<T>&);

template<typename T>
void Sort(list<T>&, int);

int main()
{
	list<int> list{ 3,5,8,5,10,5,2,1 };
	Print(list);

	int separateNum = 0;
	cout << "��؂肽������";
	cin >> separateNum;
	Sort(list, separateNum);
	Print(list);
}

template<typename T>
void Sort(list<T>& list, int separateNum)
{
	auto separateStart = find(list.begin(), list.end(), separateNum);
	auto separateEnd = separateStart;

	for (auto iter = list.begin(); iter != list.end(); ++iter)
	{
		//��؂肽���������O�ɑ傫������������ꍇ�����ɔ�΂�
		//��������ɂ���ꍇ�擪�ɔ�΂�
		//���l�������炻�̂܂�

		//��؂肽���������O�̏ꍇ
		if (iter < separateStart)
		{
			if (*iter > *separateEnd)
			{
				list.emplace_back(*iter);
			}
		}

		//��؂肽�������Ɠ��l�̏ꍇ
		if (iter > separateEnd)
		{

		}
	}
}

	template<typename T>
	void Print(const list<T>&list)
	{
		for (auto i : list)
		{
			cout << i;
		}
		cout << endl;
	}