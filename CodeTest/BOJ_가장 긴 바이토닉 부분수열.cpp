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
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int main()
{
	fastio;

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	vector<int> dpInc;
	vector<int> dpIncCnt;
	for (int i = 0; i < n; ++i)
	{
		int idx = lower_bound(dpInc.begin(), dpInc.end(), nums[i]) - dpInc.begin();
		if (idx == dpInc.size())
			dpInc.push_back(nums[i]);
		else
			dpInc[idx] = nums[i];

		dpIncCnt.push_back(dpInc.size());
	}
	
	vector<int> dpDec;
	vector<int> dpDecCnt;
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		int idx = lower_bound(dpDec.begin(), dpDec.end(), nums[i]) - dpDec.begin();
		if (idx == dpDec.size())
			dpDec.push_back(nums[i]);
		else
			dpDec[idx] = nums[i];

		dpDecCnt.push_back(dpDec.size());
	}

	int ans = 1;
	
	for (int i = 0; i < n; ++i)
		ans = max(ans, dpIncCnt[i] + dpDecCnt[n - i - 1] - 1);

	cout << ans;


	return 0;
}


// S : 532
// U : 
// T : 
// C :
// Total :
