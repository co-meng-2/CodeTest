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

int p[500000]{};
int Find(int n)
{
	if (p[n] < 0) return n;
	return p[n] = Find(p[n]);
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return false;
	p[a] += p[b];
	p[b] = a;
	return true;
}

int v, e;

int main()
{
	fastio;
	cin >> v >> e;

	memset(p, -1, sizeof(p));
	vector<pii> inputs;
	for(int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;
		inputs.push_back({ a,b });
	}

	int idx = 1;
	for(auto [a,b] : inputs)
	{
		if (Union(a, b) == false)
		{
			cout << idx;
			return 0;
		}
		++idx;
	}

	cout << 0;
	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
