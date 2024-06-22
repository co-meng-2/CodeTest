#include <iostream>
#include <unordered_set>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;


const int pivot = 2'000'000;
ll memo1[4'000'001]{};
ll memo2[4'000'001]{};
int main()
{
	fastio;

	int n, s;
	cin >> n >> s;

	vector<int> nums(n);

	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	for(int cnt = 1; cnt <= n / 2; ++ cnt )
	{
		vector<bool> permu(n/2 , false);
		for(int i = 0; i < cnt; ++i)
		{
			permu[i] = true;
		}

		do
		{
			int sum = 0;
			for(int i = 0; i < permu.size(); ++i)
			{
				if(permu[i])
				{
					sum += nums[i];
				}
			}
			memo1[sum + pivot]++;
		} while (prev_permutation(permu.begin(), permu.end()));
	}

	int val = n - n / 2;
	for (int cnt = 1; cnt <= val; ++cnt)
	{
		vector<bool> permu(val, false);
		for (int i = 0; i < cnt; ++i)
		{
			permu[i] = true;
		}

		do
		{
			int sum = 0;
			for (int i = 0; i < permu.size(); ++i)
			{
				if (permu[i])
				{
					sum += nums[n / 2 + i];
				}
			}
			memo2[sum + pivot]++;
		} while (prev_permutation(permu.begin(), permu.end()));
	}

	ll ans = 0;
	for (int i = -pivot; i <= pivot; ++i)
		if(pivot + s - i >= 0)
			ans += memo1[pivot + i] * memo2[pivot + s - i];

	ans += memo1[pivot + s];
	ans += memo2[pivot + s];

	cout << ans;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :