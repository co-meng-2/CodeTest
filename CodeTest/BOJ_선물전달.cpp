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
#include <set>
#include <string>
using namespace std;

using ll = long long;

ll dp[1'000'001]{};
ll mod = 1'000'000'000;

int main()
{
	fastio;

	int n;
	cin >> n;

	dp[2] = 1;
	dp[3] = 2;

	for(int i = 4; i <=n; ++i)
	{
		dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % mod;
	}

	cout << dp[n];

	return 0;
}


// S : 7:42
// U : 7:42
// T : 
// C :
// Total :