#include <vector>

using namespace std;

int MOD = 20170805;

// 0 R 1 D
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map)
{
    int answer = 0;
    int table[500][500][2]{};
    // 오른쪽 아래로만 움직임
    // 금지 : 아래 경우 직진 / 오른쪽 경우 아래로만 

    if (m == 1 && n == 1) return 1;

    if (city_map[1][0] != 1)
        table[1][0][1] = 1;
    if (city_map[0][1] != 1)
        table[0][1][0] = 1;

    // 5 1 
    for (int dist = 2; dist <= m + n - 2; ++dist)
    {
        for (int y = 0; y <= dist; ++y)
        {
            int x = dist - y;
            if (y >= m || x >= n) continue;
            if (city_map[y][x] == 1) continue;

            if (x >= 1)
            {
                if (city_map[y][x - 1] == 0)
                {
                    table[y][x][0] += table[y][x - 1][0] + table[y][x - 1][1];
                }
                else if (city_map[y][x - 1] == 2)
                {
                    table[y][x][0] += table[y][x - 1][0];
                }
            }

            if (y >= 1)
            {
                if (city_map[y - 1][x] == 0)
                {
                    table[y][x][1] += table[y - 1][x][0] + table[y - 1][x][1];
                }
                else if (city_map[y - 1][x] == 2)
                {
                    table[y][x][1] += table[y - 1][x][1];
                }
            }

            table[y][x][0] %= MOD;
            table[y][x][1] %= MOD;
        }
    }

    answer = (table[m - 1][n - 1][0] + table[m - 1][n - 1][1]) % MOD;
    return answer;
}