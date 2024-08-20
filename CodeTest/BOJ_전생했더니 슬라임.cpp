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
const int MOD = 1'000'000'007;

// 큰 수를 가장 적게 곱하고, 작은 수를 곱해야 한다. -> GREEDY

int main()
{
	fastio;

	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		priority_queue<ll, vector<ll>, greater<>> PQ;
		for(int i = 0; i <n; ++i)
		{
			ll num;
			cin >> num;
			PQ.push(num);
		}

		ll ans = 1;
		while(PQ.size() >= 2)
		{
			ll a = PQ.top();
			PQ.pop();
			ll b = PQ.top();
			PQ.pop();
					
			ans = a * b % MOD * ans % MOD;
			PQ.push(a * b);
		}

		cout << ans << "\n";
	}

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :

