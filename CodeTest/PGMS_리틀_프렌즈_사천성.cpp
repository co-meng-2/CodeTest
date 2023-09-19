#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ��õ�� ��θ� �� �� ���Ϸ� ���� �� �ִ�.
// ��� �󿡴� ��ֹ��� ����� �Ѵ�

// ����
// ��Ģ�� ���� Ÿ�� ��� ���� ��������, �� ��� � ������ Ÿ���� �����ϸ� �Ǵ��� ���ϴ� ���α׷�.
// �ذ� ���� -> �ѱ��ھ� ���ڿ�, �ذ� X -> IMPOSSIBLE

// ����
// �Է��� mxn 1 - 100
// board -> m�� ũ�⿡ n������ ���ڿ��� ����
// . ��ĭ, * ���� ĭ
// A-Z ���� ���ڷ� �̷���� Ÿ�� 2������ ����

// Ǯ��
// �ظ� �ϳ��� ã���� �ȴ� -> dfs backtracking���� ����
// A-Z 26���� A-Z�� ���� �μ� �� �ִ��� �ƴ����� depth�� ���� �ʹ� ��찡 ������ + ��� Ž����
// �׷��ٸ� BFS�� �� ���ĺ� �ڸ����� ��θ� ã�ƺ�. level�� ���� �� �ִ� ���ĺ��� üũ
// �� �������� ���� �� �ִ� ���ĺ��� ���ٸ� IMPOSSIBLE

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

    // int�� ��ȯ�� board
    vector<vector<int>> iBoard(m);
    // vecAlp -> ���ĺ��� ��ġ
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

    while (true) // a -> z BFS ����
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

                // �����¿�� ������
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

// 2�ð� 29��