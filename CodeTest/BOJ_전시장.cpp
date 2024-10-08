#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int n, s;

struct info
{
	int h;
	int w;

	bool operator<(const info& rhs)
	{
		if (h == rhs.h)
			return w > rhs.w;
		return h < rhs.h;
	}
};
// pii 작, 큰 순으로 sort
int dp[20000001]{};

int main()
{
	fastio;

	cin >> n >> s;
	vector<info> infos(n);
	for (int i = 0; i < n; ++i)
	{
		int h, c;
		cin >> h >> c;
		infos[i] = { h,c };
	}

	sort(infos.begin(), infos.end());

	int NxtIdx = 0;
	for (int i = 0; i <= infos.back().h; ++i)
	{
		dp[i] = dp[i - 1];
		while (NxtIdx < n && infos[NxtIdx].h == i)
		{
			dp[i] = max(dp[i], dp[i - s] + infos[NxtIdx].w);
			++NxtIdx;
		}
	}

	cout << dp[infos.back().h];


	return 0;
}


// S : 653
// U : 654
// T : 700
// C : 715
// Total : 22min
