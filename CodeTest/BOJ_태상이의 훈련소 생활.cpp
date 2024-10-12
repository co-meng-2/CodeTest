#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

// 스위핑

int n, m;
int sum[100002]{};
int sweep[100002];

int main()
{
	fastio;

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> sum[i];
	}

	for(int i = 0; i < m; ++i)
	{
		int s, e, w;
		cin >> s >> e >> w;
		sweep[s] += w;
		sweep[e + 1] += -w;
	}

	for(int i = 2; i <= n; ++i)
	{
		sweep[i] += sweep[i - 1];
	}

	for (int i = 1; i <= n; ++i)
		cout << sweep[i] + sum[i] << " ";

	return 0;
}


// S : 336
// U : 337
// T : 338
// C : 344
// Total : 8min
