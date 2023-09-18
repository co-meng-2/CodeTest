#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// 직사각형의 겹쳐진 형태의 지형
// 다각형의 가장 바깥쪽 둘레를 따라 움직임
// 꼭짓점에서 만나거나 변이 겹치는 경우는 없음
// 분리된 경우도 없음, 완전히 포함되는 경우도 없음

// 조건
// rectangle 세로 행 길이 (1 ~ 4)
// 직사각형의 좌표값 (1~50)
// character, item -> 테두리 위의 한 점, 둘이 같은 경우는 없음
// 직사각형은 최대 4개

// 풀이
// board로 표현하고 빈 곳 0, 막힌 곳 1, 경로 1로 표현 후 양 방향으로 돌아보면 나올 것 같다.

// 문제
// 캐릭터 위치, item위치, 직사각형 정보가 있을 때, 아이템을 줍기 위한 최단 거리는?

// 풀이

int board[101][101]{};
enum TYPE
{
    NONE,
    BLOCK,
    PATH,
};

// board 갱신
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