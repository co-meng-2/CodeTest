#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX = 100001;

int visited[MAX];

// �θ� �ڽ� �� �θ� Ű�°� �׻� �̵� -> leaf node�� ã�� �θ� Ų��.
int ans = 0;
void dfs(int s, int p, vector<vector<int>>& vec)
{
    for (auto it : vec[s])
    {
        if (it != p) // �ڽ��϶���
            dfs(it, s, vec);
    }

    if (s != 1 && !visited[p] && !visited[s])
    {
        visited[p] = true;
        ++ans;
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;

    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < lighthouse.size(); ++i)
    {
        adjList[lighthouse[i][0]].push_back(lighthouse[i][1]);
        adjList[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }

    dfs(1, -1, adjList);
    answer = ans;
    return answer;
}

int main()
{
    return 0;
}