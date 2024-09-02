#include <unordered_set>
#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

unordered_set<int> sums;
int nums[1000]{};
int n;

int main()
{
	fastio;

	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			sums.insert(nums[i] + nums[j]);

	for(int i = n - 1; i >= 0; --i)
	{
		for(int j = 0; j <= i; ++j)
		{
			if (sums.count(nums[i] - nums[j]))
			{
				cout << nums[i];
				return 0;
			}
		}
	}

	return 0;
}



// S : 
// U : 
// T : 
// C :
// Total :
