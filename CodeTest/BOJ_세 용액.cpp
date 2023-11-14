#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <climits>
#include <cmath>

int main()
{
	fastio;

	int N;
	cin >> N;
	vector<long long> fluids(N);
	for (int i = 0; i < N; ++i)
		cin >> fluids[i];

	std::sort(fluids.begin(), fluids.end());

	int ans[3] = {};
	long long min = (1LL << 63) - 1;
	for (int first = 0; first < N - 2; ++first)
	{
		for (int second = first + 1; second < N - 1; ++second)
		{
			long long sum = fluids[first] + fluids[second];

			int lo = second + 1;
			int hi = N - 1;

			while (lo + 1 < hi)
			{
				int mid = (lo + hi) / 2;

				if (fluids[mid] + sum <= 0)
				{
					lo = mid;
				}
				else
				{
					hi = mid;
				}
			}

			if (min > std::llabs(sum + fluids[lo]) || min > std::llabs(sum + fluids[hi]))
			{
				ans[0] = first;
				ans[1] = second;
				if (std::llabs(sum + fluids[lo]) < std::llabs(sum + fluids[hi]))
				{
					ans[2] = lo;
					min = std::llabs(sum + fluids[lo]);
				}
				else
				{
					ans[2] = hi;
					min = std::llabs(sum + fluids[hi]);
				}
			}
		}
	}

	for(int i = 0; i < 3 ; ++i)
	{
		cout << fluids[ans[i]] << " ";
	}

	return 0;
}

// 산성 양수 / 알칼리성 음수
// 같은 양의 세 가지 용액을 혼합하여 특성값이 0에 가장 가까운 용액 만들어야 함.

// N 전체 용액의 수 3 - 5000
// N^3 시간초과
// 용액을 sort
// 2개를 선택하고 나머지 하나를 이분탐색으로 찾는다.

// S : 10:46
// U : 10:48
// T : 10:52
// C : 11:40
// Total : 54min