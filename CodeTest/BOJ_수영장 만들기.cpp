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

// 각 칸의 상하좌우의 최대값으로 채울 수 있는게 아닐까? 아닌듯 함.
// 가두고 있는 것에 최소 값으로 물을 채워야 한다.
// 높이 1부터 시작해서 BFS다 돌려보고 가두고 있다고 판단되면 물 채우고 아니면 말고.
	
int n, m;
int board[50][50]{};		// 높이 기록
vector<pii> infos[10]{};	// 각 높이의 인덱스 기록
int visited[50][50]{};		// 방문 기록 

bool OOB(int y ,int x)
{
	return y < 0 || x < 0 || y >= n || x >= m;
}

int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
			infos[c - '0'].push_back({ i,j });
		}
	
	int ans = 0;
	for (int i = 1; i <= 8; ++i) // 물을 채울 곳의 높이
	{
		for (auto [y, x] : infos[i])
		{
			bool bCan = true; // 물을 채울 수 있는가?
			if (visited[y][x] >= i) continue;
			visited[y][x] = i; // visited 다시 0으로 채워주기 싫어서 어떤 높이까지의 visited를 기록.

			queue<pii> Q;
			Q.push({ y,x });
			vector<pii> changes;
			changes.push_back({ y,x });

			while (!Q.empty())
			{
				auto [cy, cx] = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; ++dir)
				{
					int ny = cy + dy[dir];
					int nx = cx + dx[dir];

					if (OOB(ny, nx)) { bCan = false; continue; } // BFS 돌다가 밖으로 나갔다 -> 바깥과 닿아있으므로 물을 채울 수 없음.
					if ( visited[ny][nx] == i || i < board[ny][nx]) continue; // 해당 단계에서 이미 방문했는가? | 다음 높이가 더 높은가?
					
					visited[ny][nx] = i;
					changes.push_back({ ny, nx }); // 순회한 좌표 기록
					Q.push({ ny, nx });
				}
			}

			// 물을 채울 수 있다면
			if (bCan)
			{
				for (auto [cy, cx] : changes)
				{
					// 물의 높이를 1 높임.
					ans++;
					board[cy][cx]++; 
					infos[i + 1].push_back({ cy,cx }); // 해당 위치가 높이가 1증가 했으므로 다시 넣어줌.
				}
			}
		}
	}

	cout << ans;

	return 0;
}


// S : 4 23
// U : 4 25
// T : 5 00 
// C : 5 53
// Total : 1h 30m

// Comment
// 구현은 어려와.
