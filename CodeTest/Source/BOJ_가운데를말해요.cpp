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

// 2개의 PQ를 준비 Inc Dec
// 어떤 수가 들어왔을 때, 각 PQ의 Top을 비교하여, 어디에 넣어야 하는 수인지 판단.
// Deq의 갯수가 Inc보다 많을 때, Inc로 Top을 빼서 넣어줌.
// Inc의 Top을 출력

int N;
int Nums[100000];
priority_queue<int> PQ_Inc;
priority_queue<int, vector<int>, greater<>> PQ_Dec;

int main()
{
	fastio;

	cin >> N;
	
	for(int i = 0; i < N; ++i)
	{
		cin >> Nums[i];
	}

	PQ_Inc.push(Nums[0]);
	cout << Nums[0] << '\n';

	for(int i = 1; i < N; ++i)
	{
		int Num = Nums[i];
		if(PQ_Inc.top() < Num)
		{
			PQ_Dec.push(Num);
		}
		else
		{
			PQ_Inc.push(Num);
		}

		if(PQ_Inc.size() < PQ_Dec.size())
		{
			PQ_Inc.push(PQ_Dec.top());
			PQ_Dec.pop();
		}

		if(PQ_Dec.size() + 1 < PQ_Inc.size())
		{
			PQ_Dec.push(PQ_Inc.top());
			PQ_Inc.pop();
		}

		cout << PQ_Inc.top() << '\n';
	}
	
	return 0;
}


// S : 933
// U : 934
// T : 937
// C : 947
// Total : 14min
