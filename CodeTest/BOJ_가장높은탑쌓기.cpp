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

// 무게, 밑면 

tiii infos[101]{};
pii dp[101]{};
vector<vector<pii>> adjList;
int dfs(int cur)
{
	if (dp[cur].first != 0) return dp[cur].first;

	auto [s, h, w] = infos[cur];

	int mx = 0;
	int mxIdx = -1;
	for(int i = 0; i < adjList[cur].size(); ++i)
	{
		auto [nw, nxt] = adjList[cur][i];
		int val = dfs(nxt);
		if(mx < val)
		{
			mx = val;
			mxIdx = nxt;
		}
	}
	dp[cur].second = mxIdx;

	if (mxIdx == -1)
	{
		dp[cur].first = h;
		return h;
	}
	dp[cur].first = h + mx;
	return dp[cur].first;
}

int main()
{
	fastio;

	int n;
	cin >> n;

	// 넓, 높, 무

	for(int i = 0; i < n; ++i)
	{
		int s, h, w;
		cin >> s >> h >> w;
		infos[i] = { s,h,w };
	}

	adjList.resize(n);
	for(int i =0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
		{
			auto [as, ah, aw] = infos[i];
			auto [bs, bh, bw] = infos[j];

			if(aw < bw && as < bs)
				adjList[j].push_back({ ah, i });
			else if(aw > bw && as > bs)
				adjList[i].push_back({ bh, j });
		}

	int mx = 0;
	int mxIdx = -1;
	for(int i = 0; i < n; ++i)
	{
		if( mx < dfs(i))
		{
			mxIdx = i;
			mx = dp[i].first;
		}
	}

	stack<int> ans;
	while(mxIdx != -1)
	{
		ans.push(mxIdx);
		mxIdx = dp[mxIdx].second;
	}

	cout << ans.size() << "\n";
	while (!ans.empty())
	{
		cout << ans.top() + 1 << "\n";
		ans.pop();
	}

	return 0;
}


// S : 200
// U : 
// T : 
// C :
// Total :
