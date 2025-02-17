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

// 2 -> 0, 1
// 3 -> 1, 2 -> 0, 1 1 -> 0(1) 1 (2)
// 4 -> 2, 3 -> 2, 3 -> 0(2) 1(3)
// 5 -> 3, 4 -> 3, 4 -> 0(3) 1 (5)

// f(n) = f(n-2) * 2 + f(n-3)

ll N;
unordered_map<ll, ll> Memo;

const int Mod = 1000000007;

ll Go(ll Cur)
{
	if(Memo.find(Cur) != Memo.end())
	{
		return Memo[Cur];
	}

	if(Cur % 2)
	{
		Memo[Cur] = (Go(Cur / 2 + 1) * Go(Cur / 2 + 1) % Mod + Go(Cur / 2) * Go(Cur / 2) % Mod) % Mod; 
		return Memo[Cur];
	}
	else
	{
		Memo[Cur] = (Go(Cur / 2) * Go(Cur / 2 + 1) % Mod + Go(Cur / 2 - 1) * Go(Cur / 2) % Mod) % Mod; 
		return Memo[Cur];
	}
}


int main()
{
	fastio;

	cin >> N;

	Memo[0] = 0;
	Memo[1] = 1;
	Memo[2] = 1;
	if(N == 0)
	{
		cout << 0;
		return 0;
	}

	if(N == 1)
	{
		cout << 1;
		return 0;
	}

	cout << Go(N);

	return 0;
}


// S : 4 10
// U : 4 10
// T : 
// C :
// Total :
