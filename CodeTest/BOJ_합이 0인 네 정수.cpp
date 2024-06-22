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
#include <unordered_set>
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

// 1600만 -> 16mb 

int main()
{
	fastio;

	int n;
	cin >> n;
	vector<vector<int>> nums(4, vector<int>(n));
	for (int j = 0; j < n; ++j)
		for (int i = 0; i < 4; ++i)
			cin >> nums[i][j];

	unordered_map<int, int> memo;
	memo.reserve(16'000'000);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
		{
			int sum = nums[0][i] + nums[1][j];
			memo[sum]++;
		}

	ll ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int sum = nums[2][i] + nums[3][j];
			if (memo.find(-sum) != memo.end())
				ans += memo.find(-sum)->second;
		}

	cout << ans;

	return 0;
}


// S : 315
// U : 
// T : 
// C :
// Total :