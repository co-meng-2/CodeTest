#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

// 전체 수 - 앞에서 나보다 큰 수 갯수 - (뒤에 남은 수 - 뒤에서 나보다 작은 수)
// 정리하면 -> 뒤에서 나보다 작은 수 + 현재 위치 - 앞에서 나보다 큰 수
//             [    현재 가능한 가장 큰 수     ]

int n, m;
int memo[100001]{};
int memo2[100001]{};
int visited[100001]{};
int ans[100001]{};


int main()
{
	fastio;

	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		memo[b]++;
		memo2[a]++;
	}

	for(int i = 1; i <= n; ++i)
	{
		ans[i] = i - memo[i] + memo2[i];
		if(visited[ans[i]])
		{
			cout << -1;
			return 0;
		}
		visited[ans[i]] = true;
	}


	for (int i = 1; i <=n; ++i)
		cout << ans[i] << " ";

	return 0;
}


// S : 2 06
// U : 2 12
// T : 2 25
// C : 2 36
// Total : 30min
