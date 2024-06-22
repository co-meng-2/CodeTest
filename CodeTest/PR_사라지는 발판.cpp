#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct tPos
{
    int y;
    int x;
};

struct tInfo
{
    bool win;
    int val;
};

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

tInfo dfsB(tPos aPos, tPos bPos, vector<vector<int>>& board, int depth);

tInfo dfsA(tPos aPos, tPos bPos, vector<vector<int>>& board, int depth = 0)
{
    if (board[aPos.y][aPos.x] == 0)
        return { true, depth };

    vector<tInfo> rets;

    bool check = false;
    for (int i = 0; i < 4; ++i)
    {
        int ny = aPos.y + dy[i];
        int nx = aPos.x + dx[i];

        if (board[ny][nx] == 0) continue;
        board[aPos.y][aPos.x] = 0;

        rets.push_back(dfsB({ ny, nx }, bPos, board, depth + 1));

        board[aPos.y][aPos.x] = 1;
        check = true;
    }

    if (!check)
        return { true, depth };

    bool isWin = false;
    int Min = 1e9;
    int Max = -1;
    for (auto [win, val] : rets)
    {
        if (win)
            Min = min(Min, val);
        else
            Max = max(Max, val);
        isWin |= win;
    }

    if (isWin)
        return { !isWin, Min };
    else
        return { !isWin, Max };
}

tInfo dfsB(tPos aPos, tPos bPos, vector<vector<int>>& board, int depth = 0)
{
    if (board[bPos.y][bPos.x] == 0)
        return { true, depth };

    vector<tInfo> rets;

    bool check = false;
    for (int i = 0; i < 4; ++i)
    {
        int ny = bPos.y + dy[i];
        int nx = bPos.x + dx[i];

        if (board[ny][nx] == 0) continue;
        board[bPos.y][bPos.x] = 0;

        rets.push_back(dfsA(aPos, { ny, nx }, board, depth + 1));

        board[bPos.y][bPos.x] = 1;
        check = true;
    }

    if (!check)
        return { true, depth };

    bool isWin = false;
    int Min = 1000000000;
    int Max = -1;
    for (auto [win, val] : rets)
    {
        if (win)
            Min = min(Min, val);
        else
            Max = max(Max, val);
        isWin |= win;
    }

    if (isWin)
        return { !isWin, Min };
    else
        return { !isWin, Max };
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;

    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> newboard(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            newboard[i][j] = board[i - 1][j - 1];

    tPos aPos{ aloc[0] + 1, aloc[1] + 1 };
    tPos bPos{ bloc[0] + 1, bloc[1] + 1};

    answer = dfsA(aPos, bPos, newboard).val;

    return answer;
}

int main()
{
    vector<vector<int>> board{{1,1,1},{1,1,1},{1,1,1}};
    vector<int> aloc{1,0};
	vector<int> bloc{1,2};

    solution(board,aloc, bloc);
    return 0;
}