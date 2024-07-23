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
using tiiii = tuple<int, int, int, int>;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;



int n, k;
vector<tiiii> infos;
int dp[100][100001]{};

int main()
{
	fastio;

	cin >> n >> k;
	infos.resize(n);
	for(int i = 0; i < n; ++i)
	{
		int at, aw, bt, bw;
		cin >> at >> aw >> bt >> bw;
		infos[i] = {at, aw, bt, bw};
	}

	auto [zat, zaw, zbt, zbw] = infos[0];
	dp[0][zat] = zaw;
	dp[0][zbt] = max(zbw, dp[0][zbt]);
	for(int i = 1; i < n; ++i)
	{
		auto [at, aw, bt, bw] = infos[i];
		for(int j = 0; j <= k; ++j)
		{
			if (!dp[i - 1][j]) continue;

			if(j+at <= k)
				dp[i][j + at] = max(dp[i - 1][j] + aw, dp[i][j + at]);
			if(j+bt <= k)
				dp[i][j + bt] = max(dp[i - 1][j] + bw, dp[i][j + bt]);
		}
	}

	cout << *max_element(begin(dp[n-1]), end(dp[n-1]));

	return 0;
}


// S : 6 44
// U : 6 46
// T : 7 00
// C : 7 17
// Total : 33min

// Comment
// dp 초깃값을 채울 때, 값이 겹칠 수 있다는 생각을 못했다... 이런...