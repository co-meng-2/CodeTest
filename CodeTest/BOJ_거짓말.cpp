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

const int Mark = 100000;

int p[51];
int Find(int n)
{
	if (p[n] < 0) return n;
	return p[n] = Find(p[n]);
}

bool Union(int parent, int child)
{
	parent = Find(parent);
	child = Find(child);

	if (parent == child) return false;
	p[parent] += p[child];
	p[child] = parent;
	return true;
}

int n, m;

int main()
{
	fastio;
	memset(p, -1, sizeof(p));
	cin >> n >> m;
	
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		int truth;
		cin >> truth;
		p[truth] = -Mark;
	}

	vector<vector<int>> party(m);
	for (int i = 0; i < m; ++i)
	{
		int cnt;
		cin >> cnt;
		int prev;
		cin >> prev;
		party[i].push_back(prev);
		--cnt;
		int nxt;
		while (cnt--)
		{
			cin >> nxt;
			party[i].push_back(nxt);
			Union(prev, nxt);
		}
	}

	int ans = 0;
	for (const auto& it : party)
	{
		if ( p[Find(it.front())] > -Mark) ans++;
	}

	cout << ans;
	
	return 0;
}


// S : 7 53
// U : 7 58
// T : 7 59
// C : 8 10
// Total : 17min
