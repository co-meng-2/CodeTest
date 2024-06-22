#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 1. 모두 낮은 경우 제외
// 2. 순위 매김

bool cmp(vector<int>& a, vector<int>& b)
{
    if ((a[0] + a[1]) == (b[0] + b[1]))
        return a[2] < b[2];
    return (a[0] + a[1]) > (b[0] + b[1]);
}

int solution(vector<vector<int>> scores) {
    int answer = -1;

    vector<vector<int>> ans;
    for (int i = 0; i < scores.size(); ++i)
    {
        scores[i].resize(3);
        scores[i][2] = i;
    }
    sort(scores.begin(), scores.end(), greater<>());

    int mb = -1;
    int nmb = scores[0][1];
    ans.push_back(scores[0]);
    for (int i = 1; i < scores.size(); ++i)
    {
        int pa = scores[i - 1][0];
        int ca = scores[i][0];
        int cb = scores[i][1];

        // 구간 바뀜
        if (pa != ca)
        {
            mb = max(mb, nmb);
            nmb = cb;
        }

        if (mb <= cb)
        {
            ans.push_back(scores[i]);
        }
    }

    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i)
    {
        if (ans[i][2] == 0)
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}