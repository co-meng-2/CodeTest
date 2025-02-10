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


int M, N, L;
int Points[100000];
pii Animals[100000];

// 거리 = L >= |a - x| + b

int main()
{
	fastio;

	cin >> M >> N >> L;

	for(int i = 0; i < M; ++i)
	{
		cin >> Points[i];
	}

	for(int i = 0; i < N;  ++i)
	{
		cin >> Animals[i].first >> Animals[i].second;
	}

	sort(Points, Points + M);

	int Ans = 0;
	for(int i = 0; i < N; ++i)
	{
		int lo = 0;
		int hi = M - 1;
		
		int l = Animals[i].first + Animals[i].second - L;
		int r = Animals[i].first - Animals[i].second + L;

		while(lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if(l <= Points[mid] && Points[mid] <= r)
			{
				++Ans;
				break;
			}
			else if(Points[mid] < l)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
	}

	cout << Ans;

	return 0;
}


// S : 9:03
// U : 9:05
// T : Failed
// C :
// Total :
