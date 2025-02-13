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

int T;

int main()
{
	fastio;

	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		vector<int> Teams(N);
		vector<int> Degree(N + 1);
		vector<int> OriginDegree;
		
		for(int i = 0; i < N; ++i)
		{
			cin >> Teams[i];
			Degree[Teams[i]] = N - 1 - i; 
		}
		OriginDegree = Degree;

		int ChangedCnt;
		cin >> ChangedCnt;
		vector<pii> Changed(ChangedCnt);
		
		for(int i = 0; i < ChangedCnt; ++i)
		{
			cin >> Changed[i].first >> Changed[i].second;
		}
		
		for(auto [A, B] : Changed)
		{
			if(OriginDegree[A] > OriginDegree[B])
			{
				swap(A,B);
			}
			++Degree[A];
			--Degree[B];
		}

		vector<int> Ans;
		for(int i = N - 1; i >=0; --i)
		{
			for(int j = 1; j <= N; ++j)
			{
				if(Degree[j] == i)
				{
					Ans.push_back(j);
					break;
				}
			}
		}

		if(Ans.size() != N)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		
		for(auto Elem : Ans)
		{
			cout << Elem << ' ';
		}
		cout << '\n';
		
	}
	

	return 0;
}


// S : 5 47 
// U : 5 49 
// T : 5 57
// C : 6 31
// Total : 44min
