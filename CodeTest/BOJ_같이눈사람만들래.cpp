#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <set>

// N : 눈덩이 갯수 4 - 600
// H : 눈덩이 지름 1 - 10^9

// 4개를 골라서 차이가 최소
// 눈덩이 배열 저장
// 눈덩이 배열 sort
// 눈덩이 4개를 뽑는다
// 이때 항상 앞 쪽에서부터 먼저 뽑음
// 4개 중 가장 앞 가장 뒤 합 - 나머지가 최소 높이 차

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
	// 4개를 선택 -> 시간초과
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

	// 2개의 합들을 배열로 저장, 합을 구성하는 인덱스도 저장
	vector<tValue> vecTwoSum;
	for(int i = 1; i <= N; ++i)
	{
		for(int j = i + 1; j <= N; ++j)
		{
			vecTwoSum.push_back({ height[i] + height[j], {i,j} });
		}
	}

	// 작은 순서대로 sort
	std::sort(vecTwoSum.begin(), vecTwoSum.end());

	// 각 합 숫자에 대해서 우측으로 가며 자신과 가장 가까운 숫자이자, 인덱스가 겹치지 않는 숫자를 찾아 minDiff를 갱신해줌.
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
// 논리에 허점이 있었다. 우선 600^4에 근접한 4개를 선택하는 방법은 시간적으로 무리가 있다.
// 그 다음 선택한 2개의 합을 이용해 다음 숫자와의 인덱스 비교 후 인덱스가 없다면 둘의 차를 계산하여 minDiff에 갱신하는 방법에서
// 옆 숫자가 인덱스를 가지고 있다면 그냥 continue해버리는 방법을 사용했다. 여기서 더 오른쪽으로 이동하며 그 수와 인덱스가 겹치지 않는 수와의 minDiff를 찾아야한다.