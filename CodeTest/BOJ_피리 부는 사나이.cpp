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

int r, c;
int board[1000][1000]{};
int visited[1000][1000]{};
int main()
{
	fastio;

	cin >> r >> c;
	for(int i = 0; i < r; ++i)
		for(int j = 0 ; j <c; ++ j)
		{
			char c;
			cin >> c;
			int dir = -1;
			if (c == 'L')
				dir = 0;
			else if (c == 'R')
				dir = 1;
			else if (c == 'U')
				dir = 2;
			else
				dir = 3;
			board[i][j] = dir;
		}


	int ans = 0;
	int mark = 1; // 이전에 방문한 곳에 재 방문할 경우 이번 레벨에서는 OK but 이전 레벨이었다면 ans를 늘려줄 필요가 없음.
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			if (visited[i][j]) continue;
			visited[i][j] = mark;

			queue<pii> Q;
			Q.push({ i, j });

			bool valid = true;
			while (!Q.empty())
			{
				auto [cy, cx] = Q.front();
				Q.pop();

				int ny = cy + dy[board[cy][cx]];
				int nx = cx + dx[board[cy][cx]];
				if (visited[ny][nx] == mark) continue;
				if (visited[ny][nx] && visited[ny][nx] != mark)
				{
					valid = false;
					break;
				}	
				visited[ny][nx] = mark;

				Q.push({ ny,nx });
			}

			if(valid)
				ans++;
			mark++;
		}

	cout << ans;


	return 0;
}


// S : 4 52
// U : 4 53
// T : 4 55
// C : 5 15
// Total : 23min
