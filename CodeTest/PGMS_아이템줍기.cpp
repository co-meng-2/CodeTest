#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// ���簢���� ������ ������ ����
// �ٰ����� ���� �ٱ��� �ѷ��� ���� ������
// ���������� �����ų� ���� ��ġ�� ���� ����
// �и��� ��쵵 ����, ������ ���ԵǴ� ��쵵 ����

// ����
// rectangle ���� �� ���� (1 ~ 4)
// ���簢���� ��ǥ�� (1~50)
// character, item -> �׵θ� ���� �� ��, ���� ���� ���� ����
// ���簢���� �ִ� 4��

// Ǯ��
// board�� ǥ���ϰ� �� �� 0, ���� �� 1, ��� 1�� ǥ�� �� �� �������� ���ƺ��� ���� �� ����.

// ����
// ĳ���� ��ġ, item��ġ, ���簢�� ������ ���� ��, �������� �ݱ� ���� �ִ� �Ÿ���?

// Ǯ��

int board[101][101]{};
enum TYPE
{
    NONE,
    BLOCK,
    PATH,
};

// board ����
void MakeBoard(vector<vector<int>>& rt)
{

    for (int i = 0; i < rt.size(); ++i)
    {
        for (int x = rt[i][0] * 2; x <= rt[i][2] * 2; ++x)
        {
            for (int y = rt[i][1] * 2; y <= rt[i][3] * 2; ++y)
            {
                if (board[y][x] == BLOCK) continue;
                if (x == rt[i][0] * 2 || x == rt[i][2] * 2 || y == rt[i][1] * 2 || y == rt[i][3] * 2)
                    board[y][x] = PATH;
                else
                    board[y][x] = BLOCK;
            }
        }
    }
}

struct tPos
{
    int y;
    int x;
    int w;
};

int dirx[4] = { 0,0,-1,1 };
int diry[4] = { -1,1,0,0 };

bool visited[101][101]{};

int bfs(tPos cur, tPos item)
{
    int ans = 0;
    queue<tPos> Q;
    Q.push(cur);
    visited[cur.y][cur.x] = true;

    while (!Q.empty())
    {
        auto front = Q.front();
        Q.pop();

        if (front.x == item.x && front.y == item.y)
        {
            ans = front.w / 2;
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int x = front.x + dirx[i];
            int y = front.y + diry[i];
            if (x < 1 || x > 100 || y < 1 || y > 100) continue;
            if (board[y][x] == PATH)
            {
                if (visited[y][x]) continue;
                visited[y][x] = true;
                Q.push({ y,x,front.w + 1 });
            }

        }
    }
    return ans;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    MakeBoard(rectangle);
    answer = bfs({ characterY * 2, characterX * 2, 0 }, { itemY * 2, itemX * 2, 0 });

    return answer;
}