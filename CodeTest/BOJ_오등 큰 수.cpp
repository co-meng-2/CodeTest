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

int n;
int cnts[1000001];
int arr[1000001];
int cntarr[1000001];
int ans[1000001];


int main()
{
	fastio;

	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		++cnts[arr[i]];
	}

	for(int i = 0; i < n; ++i)
	{
		cntarr[i] = cnts[arr[i]];
	}

	stack<int> stk;
	
	for(int i = 0; i < n; ++i)
	{
		while(!stk.empty() && cntarr[stk.top()] < cntarr[i])
		{
			ans[stk.top()] = arr[i];
			stk.pop();
		}
		stk.push(i);
	}

	for(int i = 0; i < n; ++i)
	{
		if (ans[i] == 0)
			cout << -1;
		else
			cout << ans[i];
		cout << " ";
	}

	return 0;
}


// S : 2 56
// U : 2 59
// T : 3 40
// C : 4 07
// Total : 1h 10min
