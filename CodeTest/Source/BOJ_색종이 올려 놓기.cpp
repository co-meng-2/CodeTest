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
pii arr[100];
int cnt[100];
vector<int> adjList[100];

int main()
{
	fastio;

	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	for(int i = 0; i <n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			auto [y1, x1] = arr[i];
			auto [y2, x2] = arr[j];

			if( (y1 <= y2 && x1 <= x2) || (y1 <= x2 && x1 <= y2 ))
			{
				adjList[i].push_back(j);
				cnt[j]++;
			}
			else if((y1 >= y2 && x1 >= x2) || (y1 >= x2 && x1 >= y2 ))
			{
				adjList[j].push_back(i);
				cnt[i]++;
			}
		}
	}

	queue<int> q;
	for(int i = 0; i <n; ++i)
	{
		if(cnt[i] == 0)
		{
			q.push(i);
		}
	}
	
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		
	}
	
	int depth = 0;
	while(!q.empty())
	{
		int qsz = q.size();
		while(qsz--)
		{
			int cur = q.front();
			q.pop();

			for(int nxt : adjList[cur])
			{
				if(--cnt[nxt] == 0)
				{
					q.push(nxt);
				}
			}
		}
		++depth;
	}

	cout << depth;

	set<int> a;
	sort()
	
	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
