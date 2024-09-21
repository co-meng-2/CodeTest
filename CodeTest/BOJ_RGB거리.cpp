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

// 1번집 2번집 N번집
// N번집 N-1번집
// i, i-1, i+1

int n;
vector<vector<int>> rgb(4);

int solve(vector<vector<int>> cpy, int color)
{
	for(int i = 1; i <= 3 ; ++i)
	{
		if (color == i)
			cpy[i][n] = INF;
		else
			cpy[i][1] = INF;
	}

	for(int i = 2; i <= n; ++i)
	{
		for(int j = 1; j<=3; ++j)
		{
			cpy[j][i] += min({ j == 1 ? INF : cpy[1][i-1], j == 2 ? INF : cpy[2][i-1], j == 3 ? INF : cpy[3][i-1]});
		}
	}

	return min({ cpy[1][n], cpy[2][n], cpy[3][n] });
}

int main()
{
	fastio;
	cin >> n;

	for (int i = 1; i <= 3; ++i)
		rgb[i].resize(n + 1);

	for(int i = 1; i<=n;++i)
	{
		cin >> rgb[1][i];
		cin >> rgb[2][i];
		cin >> rgb[3][i];
	}

	int mn = INF;
	for (int i = 1; i <= 3; ++i)
	{
		mn = min(mn, solve(rgb, i));
	}

	cout << mn;

	return 0;
}


// S : 935
// U : 
// T : 
// C :
// Total :
