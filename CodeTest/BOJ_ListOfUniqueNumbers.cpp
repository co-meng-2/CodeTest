#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

int main()
{
	fastio;

	int n;
	cin >> n;

	long long sum = 0;
	vector<int> nums(n);

	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	vector<int> numIdxs(100001, -1);

	// 똑같은 숫자가 2번 나오는 구간의 다음 인덱스
	int s = 0;
	// 실제 순환 인덱스
	int e = 0;

	while (e < n)
	{
		int prevIdx = numIdxs[nums[e]];
		if(prevIdx != -1)
		{
			for(int i = s; i <= prevIdx; ++i)
			{
				sum += e - i;
				numIdxs[nums[i]] = -1;
			}
			s = prevIdx + 1;
			numIdxs[nums[e]] = e;
			e++;
		}
		else
		{
			numIdxs[nums[e]] = e;
			e++;
		}
	}

	// 곱셈 -> long long 하나 넣어줘야 함
	sum += (long long)(n - s) * (n + 1 - s) / 2;

	cout << sum;


	//int sidx = 0;
	//vector<int> numIdxs(100001, -1);
	//for(int i = 0; i < n; ++i)
	//{
	//	if (numIdxs[nums[i]] == -1)
	//	{
	//		numIdxs[nums[i]] = i;
	//	}
	//	else
	//	{
	//		// 전에 있던 애들
	//		for(int j = sidx; j < numIdxs[nums[i]]; ++j)
	//		{
	//			sum += i - numIdxs[nums[j]];
	//			numIdxs[nums[j]] = -1;
	//		}
	//		sum += i - numIdxs[nums[i]];
	//		sidx = numIdxs[nums[i]] + 1;
	//		numIdxs[nums[i]] = i;
	//	}
	//}

	//for(int i = sidx; i < n; ++i)
	//{
	//	sum += n - numIdxs[nums[i]];
	//}

	// cout << sum;
	

	return 0;
}


// S : 10:11
// U : 10:11
// T : 10: 
// C :
// Total :