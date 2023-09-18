#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

struct tEdge
{
    int d;
    int w;
};

vector<vector<tEdge>> adjList;
int minIts = INT_MAX;
int minIdx = -1;
int visited[50001]{};
int GSIdx[50001]{};
int dp[50001]{}; // 간 자리에 대한 minIts
void dfs(int depth, int curIdx, int maxIts)
{
    // summit을 만남
    if (GSIdx[curIdx] == 2)
    {
        if (minIts > maxIts)
        {
            minIts = maxIts;
            minIdx = curIdx;
        }
        else if (minIts == maxIts)
        {
            minIdx = min(minIdx, curIdx);
        }

        return;
    }

    for (auto& edge : adjList[curIdx])
    {
        if (visited[edge.d]) continue;
        int nextIts = max(edge.w, maxIts);
        if (nextIts < dp[edge.d])
        {
            dp[edge.d] = nextIts;
            visited[edge.d] = true;
            dfs(depth + 1, edge.d, nextIts);
            visited[edge.d] = false;
        }
    }
}

struct tVtx
{
    int cur;
    int minIts;
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{

    adjList.resize(n + 1);

    for (auto& it : paths)
    {
        adjList[it[0]].push_back({ it[1],it[2] });
        adjList[it[1]].push_back({ it[0],it[2] });
    }

    for (auto& it : gates)
        GSIdx[it] = 1;

    for (auto& it : summits)
        GSIdx[it] = 2;

    fill(dp + 1, dp + n + 1, INT_MAX);

    // dfs
    //for(int i = 0; i < gates.size(); ++i)
    //{
    //    visited[gates[i]] = true;
    //    dfs(0, gates[i], 0);
    //}
    //
    //vector<int> answer;
    //answer.push_back(minIdx);
    //answer.push_back(minIts);
    //return answer;


    // bfs
    queue<tVtx> Q;
    for (auto& gate : gates)
        Q.push({ gate, 0 });

    while (!Q.empty())
    {
        auto front = Q.front();
        Q.pop();

        if (GSIdx[front.cur] == 2)
        {
            if (minIts > front.minIts)
            {
                minIts = front.minIts;
                minIdx = front.cur;
            }
            else if (minIts == front.minIts)
            {
                minIdx = min(minIdx, front.cur);
            }
            continue;
        }

        for (auto& edge : adjList[front.cur])
        {
            int nextIts = max(edge.w, front.minIts);
            if (nextIts < dp[edge.d])
            {
                dp[edge.d] = nextIts;
                Q.push({ edge.d, nextIts });
            }
        }
    }

    vector<int> answer;
    answer.push_back(minIdx);
    answer.push_back(minIts);
    return answer;
}