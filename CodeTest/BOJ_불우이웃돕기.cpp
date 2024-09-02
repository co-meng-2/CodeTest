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

int p[51]{};
int find(int n)
{
	if (p[n] < 0) return n;
	return p[n] = find(p[n]);
}

bool Union(int parent, int child)
{
	parent = find(parent);
	child = find(child);

	if (parent == child)  return false;

	p[parent] += p[child];
	p[child] = parent;
	return true;
}

int main()
{
	fastio;
	memset(p, -1, sizeof(p));

	int n;
	cin >> n;
	int sum = 0;

	vector<tiii> edges;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++ j)
		{
			char num;
			cin >> num;
			if (isupper(num))
				num = num - 'A' + 27;
			else if (islower(num))
				num = num - 'a' + 1;
			else
				num -= '0';

			sum += num;
			if(i != j && num != 0)
				edges.push_back({ num, i, j });
		}

	sort(edges.begin(), edges.end());

	int cnt = 0;
	int sub = 0;
	for(auto [w, a, b] : edges)
	{
		if (Union(a, b))
		{
			sub += w;
			cnt++;
		}
	}

	if (cnt < n - 1)
		cout << -1;
	else
		cout << sum - sub;


	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
