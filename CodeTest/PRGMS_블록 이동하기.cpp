#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int dp[100][100][100][100];

int r, c;
bool OOB(int y, int x)
{
    return y < 0 || x < 0 || y >= r || x >= c;
}
const int INF = 0x3f3f3f3f;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int ans = INF;
void dfs(int fy, int fx, int by, int bx, int w, vector<vector<int>>& board)
{
    if ((fy == r - 1 && fx == r - 1) || (by == r - 1 && bx == r - 1))
    {
        ans = min(ans, w);
        return;
    }

    // 일반 이동
    for (int dir = 0; dir < 4; ++dir)
    {
        int nfy = fy + dy[dir];
        int nfx = fx + dx[dir];
        if (OOB(nfy, nfx) || board[nfy][nfx] == 1) continue;
        int nby = by + dy[dir];
        int nbx = bx + dx[dir];
        if (OOB(nby, nbx) || board[nby][nbx] == 1) continue;
        if (dp[nfy][nfx][nby][nbx] <= w + 1) continue;

        dp[nfy][nfx][nby][nbx] = w + 1;
        dfs(nfy, nfx, nby, nbx, w + 1, board);
    }

    // 회전 이동
    if (fy == by)
    {
        for (int nfy : {by + 1, by - 1})
        {
            if (nfy < 0 || nfy >= r || board[nfy][bx] == 1 || board[nfy][fx] == 1) continue;
            if (dp[nfy][bx][by][bx] <= w + 1) continue;

            dp[nfy][bx][by][bx] = w + 1;
            dfs(nfy, bx, by, bx, w + 1, board);
        }

        for (int nby : {fy + 1, fy - 1})
        {
            if (nby < 0 || nby >= r || board[nby][fx] == 1 || board[nby][bx] == 1) continue;
            if (dp[fy][fx][nby][fx] <= w + 1) continue;

            dp[fy][fx][nby][fx] = w + 1;
            dfs(fy, fx, nby, fx, w + 1, board);
        }
    }
    else
    {
        for (int nfx : {bx + 1, bx - 1})
        {
            if (nfx < 0 || nfx >= c || board[by][nfx] == 1 || board[fy][nfx] == 1) continue;
            if (dp[by][nfx][by][bx] <= w + 1) continue;

            dp[by][nfx][by][bx] = w + 1;
            dfs(by, nfx, by, bx, w + 1, board);
        }

        for (int nbx : {fx + 1, fx - 1})
        {
            if (nbx < 0 || nbx >= c || board[fy][nbx] == 1 || board[by][nbx] == 1) continue;
            if (dp[fy][fx][fy][nbx] <= w + 1) continue;

            dp[fy][fx][fy][nbx] = w + 1;
            dfs(fy, fx, fy, nbx, w + 1, board);
        }
    }
}

int solution(vector<vector<int>> board) {
    r = board.size();
    c = board[0].size();

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0][1] = 0;
    dfs(0, 0, 0, 1, 0, board);

    return ans;
}

// S : 1148
// U : 1150
// T : 1200
// C : 1252
// Total : 1h 4min
