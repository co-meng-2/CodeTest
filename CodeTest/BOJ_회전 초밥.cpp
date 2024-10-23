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

int n, d, k, c;

int cnt[3001];
int sushi[3000001];

int mx = 0;
int main()
{
	fastio;
	cin >> n >> d >> k >> c;

	for(int i = 0; i < n; ++i)
	{
		cin >> sushi[i];
	}

	int curcnt = 0;
	for (int i = 0; i < k; ++i)
	{
		int cur = sushi[i];

		if (cnt[cur] == 0)
		{
			curcnt++;
		}
		cnt[cur]++;
	}

	if (cnt[c] == 0)
	{
		mx = max(mx, curcnt + 1);
	}
	else
	{
		mx = max(mx, curcnt);
	}

	int s = 1;
	while(s < n)
	{
		int e = s + k - 1;
		if (e >= n)
			e -= n;

		cnt[sushi[s - 1]]--;
		if(cnt[sushi[s-1]] == 0)
		{
			curcnt--;
		}

		if(cnt[sushi[e]] == 0)
		{
			curcnt++;
		}
		cnt[sushi[e]]++;

		if (cnt[c] == 0)
		{
			mx = max(mx, curcnt + 1);
		}
		else
		{
			mx = max(mx, curcnt);
		}

		s++;
	}

	cout << mx;

	return 0;
}


// S : 1236
// U : 1238
// T : 
// C :
// Total :
