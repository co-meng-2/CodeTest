#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// 구현 같은데..
// 레벨 bfs 구현해서 4개 이상 모인 뿌요들 기록후 한 번에 지우기?
// 터진 공간은 .으로 채워주고 레벨이 끝날 떄 마다 채워주기

char board[6][12];
bool visited[6][12];

bool OOB(int x, int y)
{
	return x < 0 || y < 0 || x >= 6 || y >= 12;
}

int main()
{
	fastio;
	for(int j = 0; j < 12; ++j)
		for(int i = 0; i < 6; ++i)
		{
			cin >> board[i][12 - j - 1];
		}

	int ans = 0;
	while (true)
	{
		memset(visited, false, sizeof(visited));
		queue<pii> Q;
		bool bChain = false;
		for(int i = 0; i < 6; ++i)
			for(int j = 0; j <12; ++j)
			{
				if (visited[i][j] || board[i][j] == '.') continue;
				visited[i][j] = true;
				Q.push({ i,j });

				vector<pii> connected;
				while(!Q.empty())
				{
					auto [cx, cy] = Q.front();
					connected.push_back({ cx,cy });
					Q.pop();

					for(int dir = 0; dir < 4; ++dir)
					{
						int nx = cx + dx[dir];
						int ny = cy + dy[dir];
						if (OOB(nx, ny) || board[nx][ny] == '.' || board[cx][cy] != board[nx][ny] || visited[nx][ny]) continue;
						visited[nx][ny] = true;
						Q.push({ nx, ny });
					}
				}

				if(connected.size() >= 4)
				{
					bChain = true;
					for(auto [x,y] : connected)
					{
						board[x][y] = '.';
					}
				}
			}

		for (int i = 0; i < 6; ++i)
		{
			int s = 0;
			for (int j = 0; j < 12; ++j)
			{
				if(board[i][j] != '.')
				{
					char tmp = board[i][j];
					board[i][j] = '.';
					board[i][s] = tmp;
					s++;
				}
			}
		}

		if (!bChain)
			break;
		ans++;
	}

	cout << ans;

	return 0;
}


// S : 2 24
// U : 2 24
// T : 2 29
// C : 3 01
// Total :
