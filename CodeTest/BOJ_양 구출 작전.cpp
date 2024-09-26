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

// 서브트리중 양수인 것만 받음

int n;
int w[123457]{};
int visited[123457]{};
vector<int> adjList[123457];
ll dfs(int cur = 1)
{
	ll sum = w[cur];
	for(auto nxt : adjList[cur])
	{
		if (visited[nxt]) continue;
		visited[nxt] = true;

		ll val = dfs(nxt);
		if (val > 0)
			sum += val;
	}

	return sum;
}

int main()
{
	fastio;
	cin >> n;

	for(int i = 2; i <= n; ++i)
	{
		char a;
		int b, c;
		cin >> a >> b >> c;
		if (a == 'W')
			b *= -1;

		adjList[i].push_back(c);
		adjList[c].push_back(i);
		w[i] = b;
	}

	visited[1] = true;
	cout << dfs();

	return 0;
}


// S : 1 46
// U : 1 49
// T : 1 55
// C : 2 03
// Total : 17min
