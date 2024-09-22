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

int n, m, k;
int simsa[100000];

using pll = pair<ll, ll>;

// m이 10억이었네 ㅋㅋ -> 매개변수 탐색으로

bool check(ll mid)
{
	ll sum = 0;
	for(int i = 0; i <n ;++i)
	{
		sum += mid / simsa[i];
		if (sum >= m)
			return true;
	}
	return false;
}

int main()
{
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> simsa[i];

	// 시간 
	ll lo = 0;
	ll hi = numeric_limits<ll>::max() / 2;
	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;
		if (check(mid) == false)
			lo = mid + 1;
		else
			hi = mid - 1;
	}

	cout << lo;

	return 0;
}


// S : 12 52
// U : 12 54
// T : 12 56
// C : 1 14
// Total : 21min
