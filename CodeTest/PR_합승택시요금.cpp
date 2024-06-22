#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    const int INF = 1'000'000'000;
    int answer = INF;

    vector<vector<int>> floyd(n + 1, vector<int>(n + 1, INF));

    for (auto& fare : fares)
    {
        int s = fare[0];
        int d = fare[1];
        int w = fare[2];
        floyd[s][d] = w;
        floyd[d][s] = w;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    floyd[i][j] = 0;
                else
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (floyd[s][i] == INF || floyd[i][a] == INF || floyd[i][b] == INF) continue;
        answer = min(answer, floyd[s][i] + floyd[i][a] + floyd[i][b]);
    }

    return answer;
}