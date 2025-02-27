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

// . 초원
// + 빙판 -> 방향으로 미끄러짐
// # 산 -> 늑대 도달 불가
// W 늑대
// 늑대가 도달할 수 없고 초원 -> P로 표시

// 두 가지 상태를 생각할 수 있어야 함.
	// 출발 가능한 곳
	// 안전한 곳

int N, M;
char Board[100][100];
bool Safe[100][100];
bool Visited[100][100];

queue<pii> Wolfs;

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= N || x >= M;
}

int main()
{
	fastio;

	memset(Safe, true, sizeof(Safe));
	cin >> N >> M;
	for(int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		for(int j = 0; j < M; ++j)
		{
			Board[i][j] = str[j];
			if(Board[i][j] == 'W')
			{
				Wolfs.push({i,j});
				Visited[i][j] = true;
			}
		}
	}

	while(!Wolfs.empty())
	{
		auto [cy,cx] = Wolfs.front();
		Wolfs.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			// Check
			if (OOB(ny, nx) || Board[ny][nx] == '#' || Visited[ny][nx])
			{
				continue;
			}

			// 다음 위치로 가면서 경로에 Marking
			while (Board[ny][nx] == '+')
			{
				Safe[ny][nx] = false;
				ny += dy[i];
				nx += dx[i];
			}

			// 산에 부딪혔다면 이전으로
			if (Board[ny][nx] == '#')
			{
				ny -= dy[i];
				nx -= dx[i];
			}

			// 이 위치에서 늑대가 시작한 적이 없다면 Q에 Push 
			if (!Visited[ny][nx])
			{
				Visited[ny][nx] = true;
				Safe[ny][nx] = false;
				Wolfs.push({ny, nx});
			}
		}
	}


	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if(Board[i][j] == '.' && Safe[i][j] == true)
			{
				cout << 'P';
			}
			else
			{
				cout << Board[i][j];
			}
		}
		cout << '\n';
	}

	return 0;
}


// S : 5 19
// U : 5 21
// T : 5 34
// C : 6 12
// Total : 53min