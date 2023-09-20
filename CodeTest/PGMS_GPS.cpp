#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// 승차 하차 위치는 오류가 없다.
// 거점에 머무를 수 있다. 왔던 길을 되돌아 갈 수 있다.
// 도로는 왕복 도로

// 문제
// 택시가 보내온 경로에서 이동 가능한 경로를 만드는 최소한의 오류 수정 횟수

// 조건
// 거점 개수 n ( 2 - 200)
// 도로의 개수 m ( 1- 10000 )
// 도로 정보 edgelist ( m x 2)
// 시간대별로 거점 정보의 총개수 k ( 2 - 100 )
// 머물렀던 거점의 정보 gps_log 
// 시작 도착 거점은 바꿀 수 없다.
// 불가능 할 경우 -1

// 풀이
// 최소 경로를 찾고, 거기에 끼워 맞춘다? ( 제 자리 or 되돌아 갈 수 있으므로 )
// 어려울 듯

// 가다가 연결된 도로가 없다.
// 1. 이번 거점 - 다음 거점과 연결된 지점에 옮긴다.
// 2. 다음 도로도 없다
// 2-1. 도로가 나올 때 까지 찾는다.
// -> 너무 분기가 많아지고, 결국 모든 경우에 대한 계산이 필요할 듯

// BFS, DFS, DP?
// depth는 100 최대
// 그래도 그래프가 dense한 경우 가지가 100개씩 뻗어나감 100^100
// backtrakcing?

// 프림으로 각 정점의 최단 거리를 구해놓음
// s -> e = Q
// 진행
// 먼저 최소거리 체크 = Q - 경유한 도로 갯수 -> 프림과 같거나 작다면 pass
// s로부터 거리 체크 + 도로가 있었는지 체크 + e까지의 거리 체크 프림으로 해보자
// s->e까지 여러 길이의 여러 경로가 있는데...
// 1. 점들에 대해 프림으로 경로가 있는 점인지 아닌지 판단
// 2. 경로가 있는 점들 중에 경로 중에 있는 점인지를 다시 나타낸다.
// 3. 점들 중 가장 많이 연결되어 있는 집합을 제외하고 나머지 점들의 위치를 바꿔야 한다.

struct tVtx
{
    int idx;
    int order;
};

void dfs(int sVtx, vector<vector<int>>& adjList, int& ans, int cnt = 1)
{
    for (int i = 0; i < adjList[sVtx].size(); ++i)
    {
        if (adjList[sVtx][i])
            dfs(adjList[sVtx][i], adjList, ans, cnt + 1);
    }
    ans = max(ans, cnt);
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log)
{
    int answer = 0;
    int prim[201][201]{};
    const int inf = 1000000000;
    for (int i = 1; i <= n; ++i)
        fill(prim[i] + 1, prim[i] + n + 1, inf);

    // 인접행렬 채우기
    for (auto& it : edge_list)
    {
        prim[it[0]][it[1]] = 1;
        prim[it[1]][it[0]] = 1;
    }

    // 프림 갱신
    for (int q = 1; q <= n; ++q)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                prim[i][j] = min(prim[i][j], prim[i][q] + prim[q][j]);

    int sVtx = gps_log[0];
    int eVtx = gps_log[k - 1];

    // 시작과 끝이 k - 1개의 경로로 닿을 수 없다면
    if (prim[sVtx][eVtx] > k - 1) return -1;

    // 시작과 끝으로부터 유효한 위치, 즉 경로로 이어질 수 있는 정점들
    vector<tVtx> vecValidVtx;
    for (int t = 1; t < k - 1; ++t)
    {
        int curVtx = gps_log[t];
        if (prim[curVtx][sVtx] > t || prim[curVtx][eVtx] > k - 1 - t) continue;
        vecValidVtx.push_back({ curVtx, t });
    }

    // 유효 정점들 간의 최대 경로
    vector<int> vecMaxLink;
    vecMaxLink.push_back(1);
    for (int i = 1; i < vecValidVtx.size(); ++i)
    {
        vecMaxLink.push_back(vecMaxLink[i - 1]);
        for (int j = i - 1; j >= 0; --j)
            if (prim[vecValidVtx[i].idx][vecValidVtx[j].idx] <= abs(vecValidVtx[i].order - vecValidVtx[j].order))
                vecMaxLink[i] = max(vecMaxLink[i], vecMaxLink[j] + 1);
    }
    int MaxLink = vecMaxLink[vecValidVtx.size() - 1];

    answer = k - 2 - MaxLink;
    return answer;
}

int main()
{
    vector<vector<int>> edge_list = { {1, 2} ,{1, 3},{2, 3},{2, 4},{3, 4},{3, 5},{4, 6},{5, 6},{5, 7},{6, 7} };
    vector<int> gps_log = { 1,2,3,3,6,7 };
    cout <<  solution(7, 10, edge_list, 6, gps_log);
    return 0;
}

// 4h