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
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using tiil = tuple<int, int, ll>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// dp[x] x원을 사용했을 때 만들 수 있는 가장 큰 수.

int main()
{
	fastio;

	int n;
	cin >> n;

	vector<int> costs(n);
	for (int i = 0; i < n; ++i)
		cin >> costs[i];

	int m;
	cin >> m;

	vector<string> dp(m + 1);

	queue<pair<int, string>> Q;

	for(int i = n-1; i >= 1; --i)
	{
		string str{};
		str += (i + '0');
		if (costs[i] <= m)
		{
			if (dp[costs[i]].size() < str.size() || (dp[costs[i]].size() == str.size() && dp[costs[i]] < str))
			{
				dp[costs[i]] = str;
				Q.push({ costs[i], str });
			}
		}
	}

	while (!Q.empty())
	{
		auto [cost, strnum] = Q.front();
		Q.pop();

		for (int i = n - 1; i >= 0; --i)
		{
			int ncost = cost + costs[i];
			string nstrnum = strnum + char('0' + i);
			if (ncost <= m )
			{
				if (dp[ncost].size() < nstrnum.size() || (dp[ncost].size() == nstrnum.size() && dp[ncost] < nstrnum))
				{
					dp[ncost] = nstrnum;
					Q.push({ ncost, nstrnum });
				}
			}
		}
	}

	if (costs[0] <= m && dp[costs[0]].size() == 0)
		dp[costs[0]] = "0";

	string ans;

	for(int i = 0; i <= m; ++i)
	{
		if (ans.size() < dp[i].size())
			ans = dp[i];
		else if (ans.size() == dp[i].size() && ans < dp[i])
			ans = dp[i];
	}

	cout << ans;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
