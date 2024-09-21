#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

int G, P;
vector<int> dest;

bool check(int mid)
{
	vector<int> acc(G + 1);
	for (int i = 1; i <= mid; ++i)
		++acc[dest[i]];

	for (int i = 1; i <= G; ++i)
	{
		acc[i] += acc[i - 1];
		if (acc[i] > i) 
			return false;
	}

	return true;
}

void solve_paremetric()
{
	int hi = P;
	int lo = 1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid))
			lo = mid + 1;
		else
			hi = mid - 1;
	}

	cout << hi;

}

int p[100001]{};
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

void solve_UnionFind()
{
	memset(p, -1, sizeof(p));

	int cnt = 0;
	for (int i = 1; i <= P; ++i)
	{
		if (Union(Find(dest[i]) - 1, dest[i]))
			cnt++;
		else
			break;
	}
	cout << cnt;
}

void solve_set()
{
	set<int, greater<>> s;

	for(int i = 1; i <= G; ++i)
		s.insert(i);

	int cnt = 0;
	for(int i = 1; i <= P; ++i)
	{
		auto it = s.lower_bound(dest[i]);
		if (it == s.end()) break;
		cnt++;
		s.erase(it);
	}

	cout << cnt;
}

int main()
{
	fastio;
	cin >> G >> P;
	dest.resize(P + 1);
	for (int i = 1; i <= P; ++i)
		cin >> dest[i];

	solve_set();

	return 0;
}


// S : 209
// U : 213
// T : 225
// C : 236
// Total : 27min
