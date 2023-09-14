#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

void Reverse(vector<vector<int>>& vec, bool isCol, int idx)
{
    if (isCol)
    {
        for (int i = 0; i < vec[idx].size(); ++i)
        {
            vec[idx][i] = !vec[idx][i];
        }
    }
    else
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            vec[i][idx] = !vec[i][idx];
        }
    }
}

void dfs(int depth, vector<vector<int>>& beg, vector<vector<int>>& tar, int& ans, int cnt = 0)
{
    if (depth >= beg.size())
    {
        for (int i = 0; i < beg[0].size(); ++i)
        {
            int difCnt = 0;
            for (int j = 0; j < beg.size(); ++j)
            {
                if (beg[j][i] != tar[j][i])
                    difCnt++;
            }

            if (difCnt == beg.size())
                cnt++; // reverse 한 것으로 침
            else if (difCnt != 0)
                return;
        }

        ans = std::min(ans, cnt);
        return;
    }

	// 행 뒤집기
	dfs(depth + 1, beg, tar, ans, cnt);

	Reverse(beg, true, depth);
	dfs(depth + 1, beg, tar, ans, cnt + 1);

	Reverse(beg, true, depth);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target)
{
    int INF = 100000000;
    int answer = INF;
    dfs(0, beginning, target, answer, 0);

    if (answer == INF)
        answer = -1;

    return answer;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> beg;
    beg.resize(n);
    for (int i = 0; i < n; ++i)
        beg[i].resize(n);

    vector<vector<int>> tar;
    tar.resize(n);
    for (int i = 0; i < n; ++i)
        tar[i].resize(n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> beg[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> tar[i][j];

	cout << solution(beg, tar);

	return 0;
}