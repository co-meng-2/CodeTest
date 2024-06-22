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
#include <set>
#include <string>
#include <memory.h>
#include <cctype>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// bfs를 여러번 한다?
// 입구 최대 400 * 26 * 10000 -> 애매
// 진행 상황을 기록하고 마지막 위치들로부터 시작

// 입구마다 bfs
// 문에서 막히면 그 위치 기록
// bfs 다 돌고 획득 열쇠로 문 땀
// 기록한 위치들로부터 다시 시작

int r, c;
int nr, nc;
bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= r+ 2 || x >= c + 2;
}

int main()
{
	fastio;
	int T;
	cin >> T;

	while (T--)
	{
		cin >> r >> c;
		nr = r + 2;
		nc = c + 2;
		vector<vector<char>> board(nr, vector<char>(nc));
		vector<vector<pii>> doors(26);
		vector<pii> starts;
		for (int i = 0; i < nr; ++i)
			for (int j = 0; j < nc; ++j)
			{
				if( (i == 0 || i == nr - 1 || j == 0 || j == nc - 1))
				{
					starts.push_back({ i, j });
					continue;
				}
					
				cin >> board[i][j];
				if (isupper(board[i][j]))
					doors[board[i][j] - 'A'].push_back({ i,j });
			}

		vector<bool> hasKey(26, false);
		string strkey;
		cin >> strkey;
		if (strkey != "0")
		{
			for (auto ch : strkey)
			{
				int keyIdx = ch - 'a';
				hasKey[keyIdx] = true;
				for (auto [y, x] : doors[keyIdx])
					board[y][x] = '.';
			}
		

		queue<pii> Q;
		queue<pii> nQ;
		vector<vector<bool>> visited(nr, vector<bool>(nc, false));
		int cnt = 0;

		for (auto [sy, sx] : starts)
		{
			Q.push({ sy, sx });
			visited[sy][sx] = true;
		}

		while (!Q.empty())
		{
			bool bChanged = false;
			while (!Q.empty())
			{
				auto [cy, cx] = Q.front();
				Q.pop();

				bool samePosPush = false;
				for (int i = 0; i < 4; ++i)
				{
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (OOB(ny, nx) || visited[ny][nx] || board[ny][nx] == '*') continue;

					if (isupper(board[ny][nx]) && !samePosPush)
					{
						nQ.push({ cy,cx });
						samePosPush = true;
					}
					else if (islower(board[ny][nx]) && !hasKey[board[ny][nx] - 'a'])
					{
						Q.push({ ny,nx });
						visited[ny][nx] = true;

						int keyIdx = board[ny][nx] - 'a';
						for (auto [dry, drx] : doors[keyIdx])
							board[dry][drx] = '.';

						board[ny][nx] = '.';
						hasKey[keyIdx] = true;
						bChanged = true;
					}
					else if(board[ny][nx] == '$')
					{
						Q.push({ ny,nx });
						visited[ny][nx] = true;
						cnt++;
					}
					else
					{
						Q.push({ ny,nx });
						visited[ny][nx] = true;
					}
				}
			}
			if (!bChanged)
				break;
			swap(Q, nQ);
		}

		cout << cnt << "\n";
	}


	return 0;
}


// S : 555
// U : 
// T : 
// C :
// Total :