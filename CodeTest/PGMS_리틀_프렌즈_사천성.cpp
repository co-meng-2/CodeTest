#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 사천성 경로를 한 번 이하로 꺾을 수 있다.
// 경로 상에는 장애물이 없어야 한다

// 문제
// 규칙에 따라 타일 모두 제거 가능한지, 그 경우 어떤 순서로 타일을 제거하면 되는지 구하는 프로그램.
// 해가 존재 -> 한글자씩 문자열, 해가 X -> IMPOSSIBLE

// 조건
// 입력판 mxn 1 - 100
// board -> m의 크기에 n글자의 문자열로 구성
// . 빈칸, * 막힌 칸
// A-Z 같은 글자로 이루어진 타일 2개씩만 존재

// 풀이
// 해를 하나라도 찾으면 된다 -> dfs backtracking으로 접근
// A-Z 26가지 A-Z가 현재 부술 수 있는지 아닌지를 depth로 쓰면 너무 경우가 많아짐 + 경로 탐색도
// 그렇다면 BFS로 각 알파벳 자리에서 경로를 찾아봄. level당 지울 수 있는 알파벳을 체크
// 한 레벨에서 지울 수 있는 알파벳이 없다면 IMPOSSIBLE

enum TYPE
{
    BLOCK = 27,
    NONE = 28
};

struct tPos
{
    int oy;
    int ox;
    int cy;
    int cx;
    int dir;
    int cnt;
    int cur;
};

string solution(int m, int n, vector<string> board) {
    string answer = "";

    int AlpCnt = 0;

    // int로 변환한 board
    vector<vector<int>> iBoard(m);
    // vecAlp -> 알파벳의 위치
    vector<tPos> vecAlp(26);
    fill(vecAlp.begin(), vecAlp.end(), tPos{ -1,-1, });
    for (int i = 0; i < m; ++i)
    {
        iBoard[i].resize(n);
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == '.')
                iBoard[i][j] = NONE;
            else if (board[i][j] == '*')
                iBoard[i][j] = BLOCK;
            else
            {
                AlpCnt++;
                iBoard[i][j] = board[i][j] - 'A';
                vecAlp[iBoard[i][j]] = { i,j };
            }
        }
    }

    AlpCnt /= 2;

    while (true) // a -> z BFS 돌림
    {
        bool isChanged = false;
        for (int i = 0; i < 26; ++i)
        {
            if (vecAlp[i].ox == -1) continue;
            queue<tPos> Q;
            Q.push({ vecAlp[i].oy, vecAlp[i].ox, -1, -1, -1, 0, i });

            while (!Q.empty())
            {
                auto front = Q.front();
                Q.pop();

                // 상하좌우로 움직임
                static tPos arrDir[4] = { {1,0,},{-1,0,},{0,1,},{0,-1,} };
                for (int j = 0; j < 4; ++j)
                {
                    int x, y;
                    if (front.cx == -1)
                    {
                        x = front.ox + arrDir[j].ox;
                        y = front.oy + arrDir[j].oy;
                    }
                    else
                    {
                        x = front.cx + arrDir[j].ox;
                        y = front.cy + arrDir[j].oy;
                    }

                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (x == front.ox && y == front.oy) continue;

                    int nextCnt = front.cnt;
                    if (front.dir != j)
                        nextCnt++;
                    if (nextCnt > 2) continue;

                    if (iBoard[y][x] == NONE)
                    {
                        Q.push({ front.oy, front.ox, y, x, j, nextCnt, front.cur });
                    }
                    else if (iBoard[y][x] == front.cur)
                    {
                        answer.push_back(front.cur + 'A');
                        iBoard[y][x] = NONE;
                        iBoard[front.oy][front.ox] = NONE;
                        vecAlp[front.cur].ox = -1;
                        isChanged = true;
                        i = 26;
                        AlpCnt--;
                        break;
                    }
                } // end of for Q push
                if (isChanged)
                    break;
            } // end while
        } // end of for alpha
        if (AlpCnt == 0)
            break;

        if (isChanged == false)
        {
            answer = "IMPOSSIBLE";
            break;
        }
    }

    return answer;
}

// 2시간 29분