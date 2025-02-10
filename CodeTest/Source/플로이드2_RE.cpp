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

int N, M;
int Floyd[101][101];
int Path[101][101];

void Go(int s, int d, vector<int>& CurPath)
{
	if(Path[s][d] == -1)
	{
		CurPath.push_back(s);
		return;
	}
	Go(s, Path[s][d], CurPath);
	Go(Path[s][d], d, CurPath);
}

int main()
{
	fastio;

	memset(Floyd, INF, sizeof(Floyd));
	memset(Path, -1, sizeof(Path));
	cin >> N >> M;
	for(int i = 0; i < M; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		Floyd[s][d] = min(Floyd[s][d],w);
	}

	for(int i = 1; i<= N; ++i)
	{
		Floyd[i][i] = 0;
	}
	
	for(int k = 1; k <= N; ++k)
	{
		for(int i = 1; i <= N; ++i)
		{
			for(int j = 1; j <=N; ++j)
			{
				if(Floyd[i][j] > Floyd[i][k] + Floyd[k][j])
				{
					Floyd[i][j] = Floyd[i][k] + Floyd[k][j];
					Path[i][j] = k;
				}
				
				
			}
		}
		
	}

	for(int i = 1; i <=N; ++i)
	{
		for(int j = 1; j <=N; ++j)
		{
			if(Floyd[i][j] == INF)
			{
				cout << '0' << ' ';
			}
			else
			{
				cout << Floyd[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	for(int i = 1; i <=N; ++i)
	{
		for(int j = 1; j <=N; ++j)
		{
			if(Floyd[i][j] == 0 || Floyd[i][j] == INF)
			{
				cout << "0\n";
				continue;
			}

			vector<int> CurPath;
			Go(i, j, CurPath);
			CurPath.push_back(j);

			cout << CurPath.size() << ' ';
			for(auto elem : CurPath)
			{
				cout << elem << ' ';
			}
			cout <<'\n';
		}
	}
	
	return 0;
}


// S : 5 27
// U : 5 30
// T : 5 38
// C : 5 57
// Total : 30min
