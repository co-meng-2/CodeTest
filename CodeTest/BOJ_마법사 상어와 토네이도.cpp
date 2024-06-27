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
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

const int INF = 0x3f3f3f3f;

int sand[4][5][5]
{
	{
		{0,0,2,0,0},
		{0,10,7,1,0},
		{5,0,0,0,0},
		{0,10,7,1,0},
		{0,0,2,0,0}
	},
};

const int MAX = 499;
int n;
int board[MAX][MAX];
int ans = 0;

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= n || x >= n;
}

// 0, 1 -> 3, 0 -> 4, 3
// r -> c / n-c -> r

int main()
{
	fastio;

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	// 모래 뿌리기 방향마다 먼저 계산
	for(int i = 1; i < 4; ++i)
	{
		for(int r = 0; r < 5;++r)
			for(int c = 0; c < 5; ++c)
			{
				sand[i][4-c][r] = sand[i - 1][r][c];
			}
	}

	pii cur = { n / 2 , n / 2};
	int progressDist = 1;
	int progressCnt = 0;
	int dir = 0;
	int changeCnt = 0;
	while ( !(cur.first == 0 && cur.second == 0) )
	{
		auto [cy, cx] = cur;
		int ny = cy + dy[dir];
		int nx = cx + dx[dir];

		// 진행마다 모래 뿌리기
		int remainSand = board[ny][nx];
		for(int i = 0; i < 5; ++i)
			for(int j = 0; j < 5; ++j)
			{
				// a에 갱신해줄 남은 모래 계산
				remainSand -= board[ny][nx] * sand[dir][i][j] / 100;

				// sand의 board안에서의 상대 위치 계산하여 그 위치에 대한 처리.
				if (OOB(ny + i - 2, nx + j - 2))
					ans += board[ny][nx] * sand[dir][i][j] / 100;
				else
					board[ny + i - 2][nx + j - 2] += board[ny][nx] * sand[dir][i][j] / 100;
			}
		// board에서의 a위치에 대한 처리 
		if (OOB(ny + dy[dir], nx + dx[dir]))
			ans += remainSand;
		else
			board[ny + dy[dir]][nx + dx[dir]] += remainSand;
		board[ny][nx] = 0;

		// 방향으로 progressDist만큼 진행.
		// 방향이 두 번 바뀌었다면 progressCnt++;
		progressCnt++;
		if(progressCnt == progressDist)
		{
			progressCnt = 0;
			dir++;
			if (dir == 4)
				dir = 0;
			changeCnt++;
			if(changeCnt == 2)
			{
				progressDist++;
				changeCnt = 0;
			}
		}
		cur = { ny, nx };
	}

	cout << ans;

	return 0;
}


// S : 5 50
// U : 1m
// T : 5m
// C : 37m
// Total : 43min

// Comment
// 보드 돌리는건 헷갈려.
