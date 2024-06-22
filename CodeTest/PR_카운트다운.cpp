#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int mnCosts[151][151]{};
bool visited[151][151][301]{};
int mn = 1e9;
int mxalp;
int mxcop;

// dfs는 안된다.
// mnCosts가 분기를 더 이상 진행시키지 않을거라는 보장이 없음.
void dfs(vector<vector<int>>& problems, int alp, int cop, int cost)
{
    // 같은  alp cop에 더 낮은 cost가 true라면
    if (alp >= mxalp && cop >= mxcop)
    {
        mn = min(mn, cost);
        return;
    }

    for (const auto& p : problems)
    {
        int areq = p[0];
        int creq = p[1];
        int arwd = p[2];
        int crwd = p[3];
        int pcost = p[4];

        // 문제 못 품
        if (areq > alp || creq > cop) continue;
        int nalp = alp + arwd;
        int ncop = cop + crwd;
        int ncost = cost + pcost;
        if (ncost > 300) continue;

        if (nalp > 150) nalp = 150;
        if (ncop > 150) ncop = 150;

        if (visited[nalp][ncop][ncost]) continue;
        if (mnCosts[nalp][ncop] <= ncost) continue;
        else mnCosts[nalp][ncop] = ncost;

        visited[nalp][ncop][ncost] = true;

        dfs(problems, nalp, ncop, ncost);
    }
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;

    problems.push_back({ 0,0,1,0,1 });
    problems.push_back({ 0,0,0,1,1 });

    vector<vector<int>> table(151, vector<int>(151, 1e9));
    queue<tiii> Q;
    Q.push({ alp, cop, 0 });
    table[alp][cop] = 0;
    while (!Q.empty())
    {
        auto [calp, ccop, ccost] = Q.front();
        Q.pop();

        for (auto p : problems)
        {
            int areq = p[0];
            int creq = p[1];
            int arwd = p[2];
            int crwd = p[3];
            int cost = p[4];

            if (areq > calp || creq > ccop) continue;

            int nalp = calp + arwd;
            int ncop = ccop + crwd;
            if (nalp > 150) nalp = 150;
            if (ncop > 150) ncop = 150;

            int ncost = ccost + cost;
            if (ncost > 300) continue;
            if (table[nalp][ncop] <= ncost) continue;
            table[nalp][ncop] = ncost;
            Q.push({ nalp, ncop, ncost });
        }
    }

    int mn = 1e9;
    for (int i = alp; i <= 150; ++i)
    {
        for (int j = cop; j <= 150; ++j)
        {
            table[i][j] = min(mn, table[i][j]);
        }
    }

    answer = mn;
    return answer;
}

int main()
{
    int a = 10;
    solution(10, 10, { {10, 15, 2, 1, 2},{20, 20, 3, 3, 4} });
    return 0;
}