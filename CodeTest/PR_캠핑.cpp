#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int GetHigh(int n, vector<int>& vec)
{
    int lo = 0;
    int hi = vec.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (vec[mid] <= n)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}

int GetHighEqual(int n, vector<int>& vec)
{
    int lo = 0;
    int hi = vec.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (vec[mid] < n)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}

int GetLow(int n, vector<int>& vec)
{
    int lo = 0;
    int hi = vec.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (vec[mid] < n)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return hi;
}

int GetLowEqual(int n, vector<int>& vec)
{
    int lo = 0;
    int hi = vec.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (vec[mid] <= n)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return hi;
}

int solution(int n, vector<vector<int>> data) {
    int answer = 0;

    set<int> set;
    vector<vector<int>> vecPos;
    sort(data.begin(), data.end());
    int idx = 0;
    for (auto& it : data)
    {
        int x = it[0];
        int y = it[1];

        if (set.find(x) == set.end())
        {
            set.insert(x);
            vecPos.push_back({});
            idx++;
        }
        vecPos[idx - 1].push_back(y);
    }

    for (int i = 0; i < vecPos.size() - 1; ++i)
    {
        for (int j = 0; j < vecPos[i].size(); ++j)
        {
            int s = 0;
            int e = 5;

            for (int k = i + 1; k < vecPos.size(); ++k)
            {
                int s_l = GetHighEqual(s, vecPos[k]);
                int e_l = GetLow(vecPos[i][j], vecPos[k]);
                if (s_l != vecPos[k].size() && e_l != -1 && s_l <= e_l)
                {
                    answer += e_l - s_l + 1;
                    s = e_l;
                }

                int s_r = GetHigh(vecPos[i][j], vecPos[k]);
                int e_r = GetLowEqual(e, vecPos[k]);
                if (s_r != vecPos[k].size() && e_r != -1 && s_r <= e_r)
                {
                    answer += e_r - s_r + 1;
                    e = s_r;
                }
            }
        }
    }

    return answer;
}

int main()
{
    solution(4, { {0, 0},{1, 1},{0, 2},{2, 0} });
}