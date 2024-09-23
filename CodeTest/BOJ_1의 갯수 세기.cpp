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

ll a, b;
ll dp[1000];
ll dp_acc[1000];

ll Calc(ll d)
{
	if (d == 1)
		return 1;
	else if (d == 0)
		return 0;

	ll ret = 0;
	ll val = 0;
	int cnt = 0;

	while ( (val * 2 + 1) < d)
	{
		val = val * 2 + 1;
		++cnt;
	}

	ret += dp_acc[cnt];
	// [0~val] + [val+1 ~ d] == [0~val] + [0 ~ d-val-1] + ( [val+1 ~ d] 구간에서 2진 수의 가장 앞자리 1을 빼준만큼의 숫자 )
	return ret + Calc(d - val - 1) + d - val;
}

int main()
{
	fastio;
	
	cin >> a >> b;
	dp[1] = 1;
	dp_acc[1] = 1;
	for(int i = 2; i <= 58; ++i)
	{
		dp[i] = dp_acc[i - 1] + powl(2LL, i - 1);
		dp_acc[i] += dp_acc[i-1] + dp[i];
	}

	cout << Calc(b) - Calc(a - 1);

	return 0;
}


// S : 2 07
// U : 2 08
// T : 2 21
// C :
// Total :
