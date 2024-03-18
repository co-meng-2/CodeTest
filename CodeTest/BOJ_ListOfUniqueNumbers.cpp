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

	// 
	int s = 0;
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

	sum += (n - s) * (n + 1 - s) / 2;

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