#include <iostream>
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
using namespace std;

using ll = long long;


int main()
{
	int n;
	cin >> n;
	int maxNum = -1;
	vector<int> nums(n + 1);
	vector<ll> left(30001, 0);
	vector<ll> right(30001, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> nums[i];
		right[nums[i]]++;
		maxNum = max(maxNum, nums[i]);
	}

	right[nums[1]]--;
	right[nums[2]]--;
	left[nums[1]]++;

	ll sum = 0;
	for(int i = 2; i < n; ++i)
	{
		int cur = nums[i];
		for(int add = 0; cur + add <= maxNum && cur - add >= 1; ++add)
		{
			if(add != 0)
				sum += right[cur + add] * left[cur - add];
			sum += right[cur - add] * left[cur + add];
		}
		right[nums[i + 1]]--;
		left[nums[i]]++;
	}

	cout << sum;
}

// S : 
// U : 
// T : 
// C :
// Total :