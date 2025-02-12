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

// 오등큰수란. G(x)
// x가 수열A(i) 에서 등장한 횟수 F(x)
// G(x)는 A(x)보다 오른쪽에 있는 수 중에 F(x)보다 큰 수 중 가장 왼쪽에 있는 수.
// N = 백만

// Brute하게는 수 하나씩 진행하며, 나머지 수 들을 비교 -> N^2으로 실패할 것.

// 이분탐색

int N;
int Nums[1000000];
int Cnt[1000001];

int main()
{
	fastio;

	cin >> N;

	vector<int> Ans(N);
	for(int i = 0; i < N; ++i)
	{
		cin >> Nums[i];
		Cnt[Nums[i]]++;
	}

	stack<int> Stk;
	for(int i = 0; i < N; ++i)
	{
		while(!Stk.empty() && Cnt[Nums[Stk.top()]] < Cnt[Nums[i]])
		{
			Ans[Stk.top()] = Nums[i];
			Stk.pop();
		}
		Stk.push(i);
	}

	for(auto Elem : Ans)
	{
		cout << (Elem ? Elem : -1) << " ";
	}

	return 0;
}


// S : 6:27
// U : 6:30
// T : 6:41 
// C :
// Total :
