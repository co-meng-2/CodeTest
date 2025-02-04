#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[3] = { 0,-1,1 };
int dy[3] = { 0,-1,1 };

const int INF = 0x3f3f3f3f;

// HW 가 1000
// 100만 개를 매번 조사하기에는...
// Q2개를 이용해 후보를 넣는식?

// .을 돌면서 보드하나 생성
// 전체 보드를 돌면서 부서진 부분 Q에 넣어줌
// 부서진 부분에서 8방에 대해 +1
// 8방중 +할 때, 자기 자신보다 커진 부분에 대해 다시 Q에 넣어주고 Mark

int H, W;
int Board[1000][1000];
int Cnt[1000][1000];

const int Mark = 10000;

bool OOB(int y, int x)
{
	return  y <0 || x < 0 || y >= H || x >= W;
}

int main()
{
	fastio;

	cin >> H >> W;

	for(int i = 0; i < H; ++i)
	{
		string str;
		cin >> str;
		for(int j = 0; j < str.size(); ++j)
		{
			if(str[j] == '.')
			{
				Board[i][j] = INF;
			}
			else
			{
				Board[i][j] = str[j] - '0';
			}
		}
	}

	queue<pii> Q;
	for(int i = 0; i < H; ++i)
	{
		for(int j = 0; j < W; ++j)
		{
			if(Board[i][j] != INF)
			{
				continue;
			}
			
			for(int n = 0; n < 3; ++n)
			{
				int ny = i + dy[n];
				for(int m = 0; m < 3; ++m)
				{
					if(n == 0 && m == 0)
					{
						continue;
					}
					
					int nx = j + dx[m];
					if(OOB(ny, nx))
					{
						continue;
					}
					
					++Cnt[ny][nx];
					if(Cnt[ny][nx] >= Board[ny][nx])
					{
						if(Board[ny][nx] != Mark)
						{
							Q.push({ny, nx});
							Board[ny][nx] = Mark;	
						}
					}
				}
			}
		}
	}

	int Wave = 0;

	while(!Q.empty())
	{
		int Qsz = Q.size();
		++Wave;
		while(Qsz--)
		{
			auto [cy, cx] = Q.front();
			Q.pop();

			Board[cy][cx] = INF;

			for(int n = 0; n < 3; ++n)
			{
				int ny = cy + dy[n];
				for(int m = 0; m < 3; ++m)
				{
					if(n == 0 && m == 0)
					{
						continue;
					}
					
					int nx = cx + dx[m];
					if(OOB(ny, nx))
					{
						continue;
					}

					++Cnt[ny][nx];
					if(Cnt[ny][nx] >= Board[ny][nx])
					{
						if(Board[ny][nx] != Mark)
						{
							Q.push({ny, nx});
							Board[ny][nx] = Mark;	
						}
					}
				}
			}
		}
	}

	cout << Wave;
	
	return 0;
}


// S : 447
// U : 448 
// T : 454 
// C : 517
// Total : 30min
