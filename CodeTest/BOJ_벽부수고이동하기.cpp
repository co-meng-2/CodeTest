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
using tiiii = tuple<int, int, int, int>;

const int INF = 0x3f3f3f3f;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int r, c;
int board[1000][1000]{};
int memo[2][1000][1000]{};

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= r || x >= c;
}

int main()
{
	fastio;
	cin >> r >> c;

	char in;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			cin >> in;
			board[i][j] = in - '0';
		}

	memset(memo, 0x3f, sizeof(memo));
	memo[0][0][0] = 1; // 안해도 된 다 생각했는데 r,c가 1 일 때 반례가 있음.

	queue<tiiii> Q;
	Q.push({ 0,0,0,1 });
	while(!Q.empty())
	{
		auto [cy, cx, cnt, move] = Q.front();
		Q.pop();

		for(int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int ncnt = cnt;

			if (OOB(ny, nx)) continue;						// OOB
			if (cnt && board[ny][nx]) continue;				// 벽 뚫은 적이 있고, 벽일 때
			if (board[ny][nx]) ncnt++;						// 벽이면 뚫음
			if (memo[ncnt][ny][nx] <= move + 1) continue;	// 그 위치에서의 최단 거리와 비교 (0 벽 안뚫음, 1 벽 뚫음) 
			memo[ncnt][ny][nx] = move + 1;					// 거리 갱신
			Q.push({ ny, nx, ncnt, move + 1 });				// Q에 넣어줌
		}
	}

	int ans = min(memo[0][r - 1][c - 1], memo[1][r - 1][c - 1]); // 도착지 벽 뚫는 거랑 안 뚫는 거랑 비교
	if (ans != INF)
		cout << ans;
	else
		cout << -1;


	return 0;
}


// S : 601
// U : 
// T : 
// C :
// Total :