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

int main()
{
	fastio;

	int n;
	cin >> n;

	int cnt1 = 0;
	int cnt2 = 0;
	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;

		cnt2 += num / 2;
		cnt1 += num % 2;

		sum += num;
	}

	if (sum % 3 != 0 || cnt1 > cnt2)
		cout << "NO";
	else
		cout << "YES";


	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
