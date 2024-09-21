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

// 서브 트리의 정점 수 = L subtree + R subtree

int n;
int r;
int q;

int dp[100001]{};
bool visited[100001]{};
vector<vector<int>> adjList;

int dfs(int cur = r)
{
	if (dp[cur]) return dp[cur];
	int sum = 1;
	for(auto nxt : adjList[cur])
	{
		if (visited[nxt]) continue;
		visited[nxt] = true;
		sum += dfs(nxt);
	}
	return dp[cur] = sum;
}

int main()
{
	fastio;

	cin >> n >> r >> q;

	adjList.resize(n + 1);
	for(int i = 0; i <n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	vector<int> ans;
	visited[r] = true;
	dfs();
	for(int i = 0; i < q; ++i)
	{
		int tar;
		cin >> tar;
		ans.push_back(dp[tar]);
	}
	
	for(auto val : ans)
	{
		cout << val << "\n";
	}

	return 0;
}


// S : 12 15 
// U : 12 15
// T : 12 15
// C : 12 24
// Total : 9min
