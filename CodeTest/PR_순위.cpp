#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

struct tInfo
{
    int cnt = 0;
    int dir = 0;
};

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<pii>> adjList(n + 1);

    for (auto result : results)
    {
        int a = result[0];
        int b = result[1];

        adjList[a].push_back({ b, 1 });
        adjList[b].push_back({ a , -1 });
    }

    vector<tInfo> infos(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        vector<bool> visited(n + 1);
        queue<tInfo> Q;
        Q.push({ i, 1 });
        Q.push({ i, -1 });
        visited[i] = true;
        while (!Q.empty())
        {
            auto [cur, dir] = Q.front();
            Q.pop();

            for (auto [next, ndir] : adjList[cur])
            {
                if (ndir == dir)
                {
                    if (visited[next]) continue;
                    visited[next] = true;
                    infos[i].cnt++;
                    Q.push({ next, ndir });
                }
            }
        }
    }

    for (auto info : infos)
    {
        if (n - 1 == info.cnt)
        {
            answer++;
        }
    }

    return answer;
}