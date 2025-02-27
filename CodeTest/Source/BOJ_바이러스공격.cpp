#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

const int INF = 0x3f3f3f3f;


// 바이러스 전파 시간, 바이러스 지연 시간, 살포 지점 갯수, 건물 갯수

int N, M;
int A, B, C, D;
char Board[1000][1000];

const char Mark = '?';

bool OOB(int y, int x)
{
    return y < 0 || x < 0 || y >= N || x >= M;
}

int main()
{
    fastio;

    cin >> N >> M >> A >> B >> C >> D;

    queue<pii> Virus;
    queue<tiii> Delayed;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Board[i][j];

            if (Board[i][j] == '*')
            {
                Virus.push({i, j});
            }
        }
    }

    int Time = 0;
    while (Time < A)
    {
        int VirusCnt = Virus.size();
        while (VirusCnt--)
        {
            auto [cy, cx] = Virus.front();
            Virus.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if (OOB(ny, nx) || Board[ny][nx] == Mark || Board[ny][nx] == '*')
                {
                    continue;
                }

                if (Board[ny][nx] == '#')
                {
                    Board[ny][nx] = Mark;
                    Delayed.push({Time + B, ny, nx});
                }
                else
                {
                    Board[ny][nx] = '*';
                    Virus.push({ny, nx});
                }
            }
        }


        while (!Delayed.empty())
        {
            auto [ct, cy, cx] = Delayed.front();
            if (ct == Time)
            {
                Board[cy][cx] = '*';
                Virus.push({cy, cx});
                Delayed.pop();
            }
            else
            {
                break;
            }
        }

        ++Time;
    }

    bool IsEmpty = true;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (Board[i][j] != '*')
            {
                cout << i + 1 << ' ' << j + 1 << '\n';
                IsEmpty = false;
            }
        }
    }

    if(IsEmpty)
    {
        cout << -1;
    }

    return 0;
}


// S : 6 13
// U : 6 16
// T : 6 18
// C : 6 38
// Total : 25min
