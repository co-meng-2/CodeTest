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



// 1. sort
// 2. s<=d 구간에서 만들어 질 수 있는 조합 수 계산
// 2-1. 1개 짜리는 그냥 더해줌
// 2-2. 2개 이상부터 구간 사이의 숫자 갯수 k에 대해서 2^k의 경우의 수를 가진다.

int arr[300000]{};
ll dp[300000]{}; // 2^k / MOD 표
int n;
const int MOD = 1'000'000'007;

int main()
{
	fastio;
	cin >> n;
	for(int i = 0; i <n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr+n);
	ll ans = 0;
	dp[0] = 1;

	for(int i = 1; i < n; ++i)
	{
		dp[i] = dp[i - 1] * 2LL % MOD;
	}

	for(int i = 0; i < n; ++i)
	{
		ans += arr[i] * (ll)dp[i] % MOD + MOD - arr[i] * (ll)dp[n - 1 - i] % MOD;
		ans %= MOD;
	}

	cout << ans;
	

	return 0;
}


// S : 3 37
// U : 3 38 -> 4 20 문제 계속 잘못 이해함...
// T : 10min
// C : 5 02
// Total : 1h25min
