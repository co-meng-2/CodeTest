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

const int INF = 0x3f3f3f3f;



// L - R 까지 팰린드롬을 만드는 최소 값
int dp[50][50]{};
string str;

int solve(int left, int right)
{
	if (dp[left][right] != INF) 
		return dp[left][right];

	if (left >= right) return 0;

	return dp[left][right] = min({solve(left, right - 1) + 1, solve(left + 1, right) + 1, solve(left + 1, right - 1) + (str[left] != str[right])});
}

int main()
{
	fastio;


	cin >> str;

	memset(dp, 0x3f, sizeof(dp));

	int ans = solve(0, str.size() - 1);

	for(int i = 0; i < str.size(); ++i)
		for(int j = i + 1; j < str.size(); ++j)
		{
			memset(dp, 0x3f, sizeof(dp));
			swap(str[i], str[j]);
			ans = min(solve(0, str.size()-1) + 1, ans);
			swap(str[i], str[j]);
		}

	cout << ans;

	return 0;
}


// S : 3 38
// U : 
// T : 
// C :
// Total :

// Comment
// 구간으로 나누는 것 까지는 생각했지만 그 후로 dp를 어떻게 적용해야할지 생각하지 못했다.