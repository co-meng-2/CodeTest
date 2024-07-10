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

// MST

struct tEdge
{
	int s;
	int d;

	double w;

	bool operator<(const tEdge& rhs) const
	{
		return w < rhs.w;
	}
};

int p[1001];
int n, m;

int Find(int n)
{
	if (p[n] < 0) return n;
	return p[n] = Find(p[n]);
}

bool Union(int parent, int child)
{
	parent = Find(parent);
	child = Find(child);

	if(parent == child)
		return false;

	p[parent] += p[child];
	p[child] = parent;
	return true;
}

int main()
{
	fastio;
	double ans = 0;
	cin >> n >> m;
	vector<pii> v;
	for(int i = 0; i < n; ++i)
	{
		int y, x;
		cin >> y >> x;
		v.push_back({ y,x });
	}

	vector<tEdge> edges;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			double w = sqrt( pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
			edges.push_back({ i, j, w});
		}

	sort(edges.begin(), edges.end());
	memset(p, -1, sizeof(p));

	for(int i = 0; i < m; ++i)
	{
		int s, d;
		cin >> s >> d;
		Union(s - 1, d - 1);
	}

	for(const auto& [s, d, w] : edges)
	{
		if (Union(s, d))
			ans += w;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;

	return 0;
}

// S : 7 12
// U : 7 13
// T : 7 15
// C : 7 30
// Total : 18min

// Comment
// 오랜만에 MST Cruscal 알고리즘을 쓰려니 헷갈린다.
// 그래도 잘 기억하고 있는듯.
