#include <iostream>
#include <vector>
using std::vector;

#include <queue>

struct tEdge
{
    int s;
    int d;
    int w;

    bool operator >(const tEdge& _rhs) const {
        return  w > _rhs.w;
    }
};

vector<int> shortestReach(int n, vector<vector<int>> edges, int s)
{
    vector<vector<tEdge>> adjList(n + 1);

    for (int i = 0; i < edges.size(); ++i)
    {
        int st = edges[i][0];
        int end = edges[i][1];
        int w = edges[i][2];

        adjList[st].push_back({ st, end, w });
        adjList[end].push_back({ end, st, w });
    }

    const int INF = 1000000000;
    vector<int> table(n + 1, INF);
    table[s] = 0;

    vector<bool> visited(n + 1, false);

    std::priority_queue<tEdge, vector<tEdge>, std::greater<tEdge>> PQ;
    PQ.push({ -1, s, 0 });

    while (!PQ.empty())
    {
        auto top = PQ.top();
        PQ.pop();

        if (visited[top.d]) continue;
        visited[top.d] = true;

        for (auto edge : adjList[top.d])
        {
            if(table[edge.d] > table[edge.s] + edge.w)
            {
                table[edge.d] = table[edge.s] + edge.w;
                PQ.push({edge.s, edge.d, table[edge.d]});
            }
        }
    }

    table.erase(table.begin() + s);
    table.erase(table.begin());


	return table;
}

int main()
{
    int T;
    std::cin >> T;

    while (T > 0)
    {
        int V, E;
        std::cin >> V >> E;

        vector<vector<int>> adjList;

        // 그래프를 인접행렬로 만들기
        for (int i = 0; i < E; ++i)
        {
            int from, to, w;
            std::cin >> from >> to >> w;
            adjList.push_back({ from, to, w });
        }

        int K;
        std::cin >> K;
        shortestReach(V, adjList, K);
        T--;
    }
}