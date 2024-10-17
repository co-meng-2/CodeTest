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

// MST
int n;
int adjMat[1000][1000];

struct tEdge
{
	int s;
	int d;
	int w;

	bool operator<(const tEdge _rhs) const
	{
		return w < _rhs.w;
	}
};

int p[1000];
int Find(int n)
{
	if (p[n] < 0)
		return n;
	return p[n] = Find(p[n]);
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b)
		return false;

	p[a] += p[b];
	p[b] = a;
	return true;
}

int main()
{
	fastio;
	memset(p, -1, sizeof(p));

	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <n; ++j)
		{
			cin >> adjMat[i][j];
		}

	vector<tEdge> edges;
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
		{
			edges.push_back({ i, j, adjMat[i][j] });
		}

	sort(edges.begin(), edges.end());

	ll ans = 0;
	for(int i = 0; i < edges.size(); ++i)
	{
		auto [s,d,w] = edges[i];
		if(Union(s, d))
		{
			ans += w;
		}
	}

	cout << ans;

	return 0;
}


// S : 203
// U : 203
// T : 203
// C : 208
// Total : 5min
