#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <set>

// N : ������ ���� 4 - 600
// H : ������ ���� 1 - 10^9

// 4���� ��� ���̰� �ּ�
// ������ �迭 ����
// ������ �迭 sort
// ������ 4���� �̴´�
// �̶� �׻� �� �ʿ������� ���� ����
// 4�� �� ���� �� ���� �� �� - �������� �ּ� ���� ��

struct tValue
{
	int value;
	std::set<int> idxs;

	bool Find(const tValue& val)
	{
		for( auto it : val.idxs)
		{
			if (idxs.find(it) != idxs.end())
				return true;
		}

		return false;
	}

	bool operator<(const tValue& _rhs) const
	{
		return value < _rhs.value;
	}
};

int main()
{
	int N;
	cin >> N;
	int height[601];
	for(int i = 1; i <= N; ++i)
	{
		cin >> height[i];
	}

	int minDiff = 1e9;
	// 4���� ���� -> �ð��ʰ�
	//for(int i = 1; i <= N; ++i)
	//{
	//	for(int j = i + 1; j <= N; ++j)
	//	{
	//		for(int k = j + 1; k <= N; ++k)
	//		{
	//			for(int t = k + 1; t <= N; ++t)
	//			{
	//				minDiff = std::min(minDiff, abs(height[i] + height[t] - (height[j] + height[k])));
	//			}
	//		}
	//	}
	//}

	// 2���� �յ��� �迭�� ����, ���� �����ϴ� �ε����� ����
	vector<tValue> vecTwoSum;
	for(int i = 1; i <= N; ++i)
	{
		for(int j = i + 1; j <= N; ++j)
		{
			vecTwoSum.push_back({ height[i] + height[j], {i,j} });
		}
	}

	// ���� ������� sort
	std::sort(vecTwoSum.begin(), vecTwoSum.end());

	// �� �� ���ڿ� ���ؼ� �������� ���� �ڽŰ� ���� ����� ��������, �ε����� ��ġ�� �ʴ� ���ڸ� ã�� minDiff�� ��������.
	for(int i = 0; i < vecTwoSum.size() - 1; ++i)
	{
		int cmpIdx = i + 1;

		bool bValid = true;
		while (vecTwoSum[i].Find(vecTwoSum[cmpIdx]))
		{
			cmpIdx++;
			if (cmpIdx >= vecTwoSum.size())
			{
				bValid = false;
				break;
			}
		}

		if(bValid)
			minDiff = std::min(minDiff, vecTwoSum[cmpIdx].value - vecTwoSum[i].value);
	}

	cout << minDiff;

	return 0;
}

// S : 2:44
// U : 2:44
// T : 2:51
// C : 3:41
// Total :53 min
// ���� ������ �־���. �켱 600^4�� ������ 4���� �����ϴ� ����� �ð������� ������ �ִ�.
// �� ���� ������ 2���� ���� �̿��� ���� ���ڿ��� �ε��� �� �� �ε����� ���ٸ� ���� ���� ����Ͽ� minDiff�� �����ϴ� �������
// �� ���ڰ� �ε����� ������ �ִٸ� �׳� continue�ع����� ����� ����ߴ�. ���⼭ �� ���������� �̵��ϸ� �� ���� �ε����� ��ġ�� �ʴ� ������ minDiff�� ã�ƾ��Ѵ�.