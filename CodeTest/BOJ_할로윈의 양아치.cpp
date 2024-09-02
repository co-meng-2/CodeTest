#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// 인수 / 사탕 수
// UnionFind + knapsack?

pii p[30001]{};
int dp[3001]{};

int Find(int n)
{
	if (p[n].first < 0) return n;
	return p[n].first = Find(p[n].first);
}

bool Union(int parent, int child)
{
	parent = Find(parent);
	child = Find(child);

	if (parent == child) return false;
	p[parent].first += p[child].first;
	p[parent].second += p[child].second;
	p[child].first = parent;
	p[child].second = 0;
	return true;
}

int n, m, k;

int main()
{
	fastio;

	memset(p, -1, sizeof(p));
	cin >> n >> m >> k;
	for(int i = 1; i <= n ;++i)
		cin >> p[i].second;

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	vector<pii> infos;
	for(int i = 1; i <= n; ++i)
	{
		if (p[i].first < 0)
			infos.push_back({ -p[i].first, p[i].second});
	}

	vector<int> cnts(infos.size(), 1);
	 // 선택 그룹 / 아이 수

	for (const auto [w, v] : infos)
		for (int j = k - 1; j >= w; --j)
			dp[j] = max(dp[j], dp[j - w] + v);


	cout << dp[k-1];

	return 0;
}

// S : 1:42
// U : 1:43
// T : 1:44
// C : 2:19
// Total : 37min