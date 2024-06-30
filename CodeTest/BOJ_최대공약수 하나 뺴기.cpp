#include <iostream>
#include <numeric>
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

const int MAX = 1000001;
int dp_front[MAX]{};
int dp_back[MAX]{};
int n;

int main()
{
	fastio;
	cin >> n;
	vector<int> nums(n+1);
	for (int i = 1; i <= n; ++i)
		cin >> nums[i];

	for(int i = 1; i <= n; ++i)
	{
		dp_front[i] = gcd(dp_front[i - 1], nums[i]);

		int backIdx = n - i + 1;
		dp_back[i] = gcd(dp_back[i - 1], nums[backIdx]);
	}

	int mx = -1;
	int mxIdx = -1;
	for(int sub = 1; sub <= n; ++sub)
	{
		int curGCD = gcd(dp_front[sub - 1], dp_back[n - sub - 1]);
		if( nums[sub] % curGCD != 0 && curGCD > mx)
		{
			mx = curGCD;
			mxIdx = sub;
		}
	}

	if (mx == -1)
		cout << -1;
	else
		cout << mx << " " << nums[mxIdx];

	return 0;
}


// S : 10 05
// U : 10 05
// T : 10 14
// C : 10 35
// Total : 30min

// Comment
// 앞 뒤로 구간 DP를 사용해야할 때가 언제인지 대충 감이 왔다.
// 전체의 경우의 수가 아닌 부분적인 경우의 수를 구해야할 때!