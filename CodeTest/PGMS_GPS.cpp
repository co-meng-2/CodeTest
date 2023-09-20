#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// ���� ���� ��ġ�� ������ ����.
// ������ �ӹ��� �� �ִ�. �Դ� ���� �ǵ��� �� �� �ִ�.
// ���δ� �պ� ����

// ����
// �ýð� ������ ��ο��� �̵� ������ ��θ� ����� �ּ����� ���� ���� Ƚ��

// ����
// ���� ���� n ( 2 - 200)
// ������ ���� m ( 1- 10000 )
// ���� ���� edgelist ( m x 2)
// �ð��뺰�� ���� ������ �Ѱ��� k ( 2 - 100 )
// �ӹ����� ������ ���� gps_log 
// ���� ���� ������ �ٲ� �� ����.
// �Ұ��� �� ��� -1

// Ǯ��
// �ּ� ��θ� ã��, �ű⿡ ���� �����? ( �� �ڸ� or �ǵ��� �� �� �����Ƿ� )
// ����� ��

// ���ٰ� ����� ���ΰ� ����.
// 1. �̹� ���� - ���� ������ ����� ������ �ű��.
// 2. ���� ���ε� ����
// 2-1. ���ΰ� ���� �� ���� ã�´�.
// -> �ʹ� �бⰡ ��������, �ᱹ ��� ��쿡 ���� ����� �ʿ��� ��

// BFS, DFS, DP?
// depth�� 100 �ִ�
// �׷��� �׷����� dense�� ��� ������ 100���� ����� 100^100
// backtrakcing?

// �������� �� ������ �ִ� �Ÿ��� ���س���
// s -> e = Q
// ����
// ���� �ּҰŸ� üũ = Q - ������ ���� ���� -> ������ ���ų� �۴ٸ� pass
// s�κ��� �Ÿ� üũ + ���ΰ� �־����� üũ + e������ �Ÿ� üũ �������� �غ���
// s->e���� ���� ������ ���� ��ΰ� �ִµ�...
// 1. ���鿡 ���� �������� ��ΰ� �ִ� ������ �ƴ��� �Ǵ�
// 2. ��ΰ� �ִ� ���� �߿� ��� �߿� �ִ� �������� �ٽ� ��Ÿ����.
// 3. ���� �� ���� ���� ����Ǿ� �ִ� ������ �����ϰ� ������ ������ ��ġ�� �ٲ�� �Ѵ�.

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

    // ������� ä���
    for (auto& it : edge_list)
    {
        prim[it[0]][it[1]] = 1;
        prim[it[1]][it[0]] = 1;
    }

    // ���� ����
    for (int q = 1; q <= n; ++q)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                prim[i][j] = min(prim[i][j], prim[i][q] + prim[q][j]);

    int sVtx = gps_log[0];
    int eVtx = gps_log[k - 1];

    // ���۰� ���� k - 1���� ��η� ���� �� ���ٸ�
    if (prim[sVtx][eVtx] > k - 1) return -1;

    // ���۰� �����κ��� ��ȿ�� ��ġ, �� ��η� �̾��� �� �ִ� ������
    vector<tVtx> vecValidVtx;
    for (int t = 1; t < k - 1; ++t)
    {
        int curVtx = gps_log[t];
        if (prim[curVtx][sVtx] > t || prim[curVtx][eVtx] > k - 1 - t) continue;
        vecValidVtx.push_back({ curVtx, t });
    }

    // ��ȿ ������ ���� �ִ� ���
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