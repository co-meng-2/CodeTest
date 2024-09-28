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

int n;
int r, c;

void dfs(int sr, int dr, int sc, int dc, int sum)
{
	if (dr == sr)
	{
		cout << sum;
		return;
	}

	int len = (dr - sr + 1) / 2;
	int add = len * len;
	int mr = (sr + dr) / 2;
	int mc = (sc + dc) / 2;
	if(r <= mr && c <= mc)
	{
		dfs(sr, mr, sc, mc, sum);
	}
	else if(r <= mr && c > mc)
	{
		sum += add;
		dfs(sr, mr, mc + 1, dc, sum);
	}
	else if(r > mr && c <= mc)
	{
		sum += add * 2;
		dfs(mr + 1, dr, sc, mc, sum);
	}
	else
	{
		sum += add * 3;
		dfs(mr + 1, dr, mc + 1, dc, sum);
	}
}

int main()
{
	fastio;
	cin >> n >> r >> c;

	dfs(0, pow(2, n) - 1, 0, pow(2, n) - 1, 0);

	return 0;
}


// S : 843
// U : 844
// T : 848
// C : 901
// Total : 18min
