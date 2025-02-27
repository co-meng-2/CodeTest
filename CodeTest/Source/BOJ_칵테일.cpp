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



int N;
vector<vector<int>> Weights;
vector<vector<tiii>> AdjList;
vector<ll> Ans;

void Dfs(int cur)
{
	for(auto [nxt, p, q] : AdjList[cur])
	{
		if(Ans[cur] / p * q != Ans[nxt])
		{
			Ans[nxt] = Ans[nxt] * Ans[cur] / p * q / gcd(Ans[cur] / p * q, Ans[nxt]); 
			Dfs(nxt);
		}
	}
}

int main()
{
	fastio;

	cin >> N;
	Weights.resize(N);
	AdjList.resize(N);
	Ans.resize(N, 1);
	for(int i = 0; i < N - 1; ++i)
	{
		int a , b , p , q;
		cin >> a >> b >> p >> q;
		
		int GCD = gcd(p, q);
		p /= GCD;
		q /= GCD;
		
		Weights[a].push_back(p);
		Weights[b].push_back(q);
		AdjList[a].push_back({b, p, q});
		AdjList[b].push_back({a, q, p});
	}

	// 비율을 서로소로 만듦. -> LCM을 기본값으로
	for(int i = 0; i < Weights.size(); ++i)
	{
		int LCM = 1;
		for(int j = 0; j < Weights[i].size(); ++j)
		{
			LCM = LCM * Weights[i][j] / gcd(Weights[i][j], LCM);
		}

		Ans[i] = LCM;
	}

	// 선택한 Cur에서의 연결된 비율에 대한 값을 비교 -> 다르다면 갱신하고 변경된 재료를 Cur로 다시 시작.
	for(int i = 0; i < Weights.size(); ++i)
	{
		Dfs(i);
	}

	for(auto elem : Ans)
	{
		cout << elem << " ";
	}
	
	return 0;
}


// S : 620
// U : 628
// T : 638
// C : 730
// Total : 1h 10min
