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

// DFS로 1번 섬 부터 시작하여, 밑으로 진행.
// leaf에서부터 부모로 자신의 값을 더해주고, 이때, 음수라면 더해주지 않음.

int n;
vector<int> AdjList[1234567];
ll Infos[1234567];

void Dfs(int Cur)
{
	for(auto Child : AdjList[Cur])
	{
		Dfs(Child);
		Infos[Cur] += Infos[Child] > 0 ? Infos[Child] : 0;
	}
}


int main()
{
	fastio;

	cin >> n;
	
	for(int i = 2; i <= n; ++i)
	{
		char t;
		int a,p;
		cin >> t >> a >> p;

		if(t == 'W')
		{
			a *= -1;
		}
		Infos[i] = a;
		AdjList[p].push_back(i);
	}

	Dfs(1);
	cout << Infos[1];

	return 0;
}


// S : 8 53
// U : 8 56
// T : 9 01
// C : 9 30
// Total : 37min
