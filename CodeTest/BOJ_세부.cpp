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

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int v, e;
int s, d;

bool check(int mid, vector<vector<pii>>& adjList)
{
	queue<int> Q;
	Q.push(s);

	vector<bool> visited(v + 1);
	visited[s] = true;

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (auto [w, nxt] : adjList[cur])
		{
			if (visited[nxt]) continue;
			if (mid > w) continue;
			if (nxt == d) 
				return true;
			visited[nxt] = true;
			Q.push(nxt);
		}
	}

	return false;
}

int Find(vector<int>& p, int n)
{
	if (p[n] < 0)  return n;
	return p[n] = Find(p, p[n]);
}

bool Union(vector<int>& p, int parent, int child)
{
	parent = Find(p, parent);
	child = Find(p, child);

	if (parent == child) return false;

	p[parent] += p[child];
	p[child] = parent;
	return true;
}

void solve_mst()
{
	vector<tiii> edges(e);
	for (int i = 0; i < e; ++i)
	{
		int st, ed, w;
		cin >> st >> ed >> w;
		edges[i] = { w, st, ed };
	}

	sort(edges.begin(), edges.end(), greater<>());

	vector<int> p(v + 1, -1);

	int ans = 1e9;

	for(auto [w, st, ed] : edges)
	{
		if(Union(p ,st, ed))
		{
			ans = min(ans, w);
			if (Find(p, s) == Find(p, d))
				break;
		}
	}

	if (Find(p, s) == Find(p, d))
		cout << ans;
	else
		cout << 0;
}

void solve_parametric_search()
{
	vector<vector<pii>> adjList(v + 1);
	for(int i = 0; i < e; ++i)
	{
		int st, ed, w;
		cin >> st >> ed >> w;
		adjList[st].push_back({ w, ed });
		adjList[ed].push_back({ w, st });
	}

	int lo = 1;
	int hi = 1000000;

	while(lo <= hi)
	{
		int mid = (lo + hi) / 2;

		if (check(mid, adjList))
			lo = mid + 1;
		else
			hi = mid - 1;
	}

	cout << hi;
}

int main()
{
	fastio;

	cin >> v >> e;
	cin >> s >> d;

	solve_mst();

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
