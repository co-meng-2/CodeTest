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

int memo[1<<10][10];
int adjMat[10][10]{};

const int INF = 0x3f3f3f3f;

int main()
{
	fastio;
	memset(memo, 0x3f, sizeof(memo));

	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> adjMat[i][j];

	queue<tiii> Q;
	Q.push({ s, 1 << s, 0 });
	memo[1 << s][s] = 0;
	while(!Q.empty())
	{
		auto [cur, cbit, cw] = Q.front();
		Q.pop();

		for(int i = 0 ;i < 10; ++i)
		{
			int nbit = cbit | (1 << i);
			int nw = cw + adjMat[cur][i];
			if (memo[nbit][i] <= nw) continue;
			memo[nbit][i] = nw;
			Q.push({i, nbit, nw});
		}
	}

	int mn = memo[ (1 << n) - 1][0];
	for(int i = 1; i < n; ++i)
	{
		mn = min(memo[(1 << n) - 1][i], mn);
	}

	cout << mn;

	return 0;
}


// S : 3 35
// U : 3 36
// T : 3 37
// C : 3 47
// Total : 12min
