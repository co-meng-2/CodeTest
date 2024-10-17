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

int p[100001];
int Find(int n)
{
	if (p[n] < 0) return n;
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

int N, Q;
struct TBalpan
{
	int x1;
	int x2;
	int y;
	int idx;

	bool operator <(const TBalpan& _rhs) const
	{
		if (x1 == _rhs.x1)
			return x2 < _rhs.x2;
		return x1 < _rhs.x1;
	}
};
TBalpan balpans[100001];

int main()
{
	fastio;
	memset(p, -1, sizeof(p));


	cin >> N >> Q;
	for(int i = 1; i <= N; ++i )
	{
		balpans[i].idx = i;
		cin >> balpans[i].x1 >> balpans[i].x2 >> balpans[i].y;
	}

	sort(balpans + 1, balpans + N + 1);

	auto cur = balpans[1];
	for(int i = 2; i <=N; ++i)
	{
		if (cur.x2 >= balpans[i].x2)
		{
			Union(cur.idx, balpans[i].idx);
		}
		else if (cur.x2 >= balpans[i].x1)
		{
			Union(cur.idx, balpans[i].idx);
			cur = balpans[i];
		}
		else
		{
			cur = balpans[i];
		}
	}

	for(int i = 0; i <Q;++i)
	{
		int a, b;
		cin >> a >> b;
		if (Find(a) == Find(b))
			cout << "1\n";
		else
			cout << "0\n";
	}


	return 0;
}


// S : 255
// U : 302
// T : 
// C :
// Total :
