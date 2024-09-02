#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using tiii = tuple<int, int, int>;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int dp[10001]{};
int n, m;

int main()
{
	fastio;
	memset(dp, 0, sizeof(dp));
	cin >> n >> m;
	vector<pii> infos;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		
		for(int num = c; num > 0; num /= 2)
		{
			int mul = num - num / 2;
			infos.push_back({ a * mul, b * mul});
		}
	}

	for (auto [w, v] : infos)
		for (int j = m ; j >= w; --j)
			dp[j] = max(dp[j], dp[j - w] + v);

	cout << dp[m];
}