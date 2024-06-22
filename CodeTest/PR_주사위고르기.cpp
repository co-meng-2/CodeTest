#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using tiii = tuple<int, int, int>;

struct tInfo
{
    vector<int> sel;
    int wins;

    bool operator<(const tInfo& rhs) const
    {
        return wins < rhs.wins;
    }
};

void dfs(int maxDepth, int depth, vector<int>& ret, vector<int>& diceIdx, vector<vector<int>>& dices, int sum = 0)
{
    if (maxDepth == depth)
    {
        ret.push_back(sum);
        return;
    }

    for (int i = 0; i < 6; ++i)
    {
        dfs(maxDepth, depth + 1, ret, diceIdx, dices, sum + dices[diceIdx[depth]][i]);
    }
}

vector<int> solution(vector<vector<int>> dices) {
    vector<int> answer;

    // A가 선택하는 주사위 조합 최대 3 * 2 * 7 * 6 = 252
    // brute (6*6/2) * (6*6/2)

    int n = dices.size();

    vector<int> permu;
    for (int i = 0; i < n / 2; ++i)
        permu.push_back(0);
    for (int i = 0; i < n / 2; ++i)
        permu.push_back(1);

    vector<tInfo> finalRet; // w d l
    do
    {
        vector<int> A;
        vector<int> B;
        for (int i = 0; i < permu.size(); ++i)
        {
            if (permu[i])
                A.push_back(i);
            else
                B.push_back(i);
        }

        vector<int> retA;
        dfs(n / 2, 0, retA, A, dices);
        sort(retA.begin(), retA.end());

        vector<int> retB;
        dfs(n / 2, 0, retB, B, dices);
        sort(retB.begin(), retB.end());

        int winCnt = 0;
        for (auto ret : retA)
        {
            winCnt += lower_bound(retB.begin(), retB.end(), ret) - retB.begin();
        }
        finalRet.push_back({ A, winCnt });
    } while (next_permutation(permu.begin(), permu.end()));

    int idx = max_element(finalRet.begin(), finalRet.end()) - finalRet.begin();

    for (auto it : finalRet[idx].sel)
    {
        answer.push_back(it);
    }

    return answer;
}

int main()
{
    solution({ {1, 2, 3, 4, 5, 6},{3, 3, 3, 3, 4, 4},{1, 3, 3, 4, 4, 4},{1, 1, 4, 4, 5, 5} });
    return 0;
}