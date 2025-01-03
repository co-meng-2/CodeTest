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

int p[200000];

int Find(int n)
{
	if(p[n] < 0 ) return n;
	return p[n] = Find(p[n]);
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if(a == b) return false;

	p[a] += p[b];
	p[b] = a;
	return true;
}

using tiii = tuple<int,int,int>;
int n, m;

struct tEdge
{
	int s;
	int d;
	int w;

	bool operator<(const tEdge& rhs)
	{
		return w < rhs.w;
	}
};

tEdge edges[200000];

int main()
{
	fastio;
	
	while(true)
	{
		memset(p,-1,sizeof(p));
		cin >> n >> m;
		
		if(n == 0 && m == 0)
			break;
	
		int sum = 0;
		for(int i = 0; i  < m ;++i)
		{
			cin >> edges[i].s >> edges[i].d >> edges[i].w;
			sum += edges[i].w;
		}
		
		sort(edges, edges + m);

		for(int i = 0; i < m; ++i)
		{
			if(Union(edges[i].s, edges[i].d))
			{
				sum -= edges[i].w;
			}
		} 

		cout << sum << "\n";
	}

	return 0;
}

// G4
// https://www.acmicpc.net/problem/6497

// S : 9 55
// U : 10 11
// T : 
// C :
// Total :
