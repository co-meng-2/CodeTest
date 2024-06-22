#include <string>
#include <vector>

using namespace std;

// 대충 200개 순열
// 몇개 계산했을 때, 계산 값 + 쓴 노드 같으면 visited로 판정? -> 그래도 안 될 듯.
// dp인데 그러면...
// 2^200

const int INF = 1e9;

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;

    vector<int> nums;
    nums.push_back(matrix_sizes[0][0]);
    for (auto it : matrix_sizes)
        nums.push_back(it[1]);

    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
    for (int i = 0; i + 2 < dp.size(); ++i)
    {
        dp[i][i + 2] = nums[i] * nums[i + 1] * nums[i + 2];
    }

    for (int add = 3; add < nums.size(); ++add)
    {
        for (int i = 0; i + add < dp.size(); ++i)
        {
            for (int divpoint = 1; divpoint <= add - 1; ++divpoint)
            {
                // i+1, i+2, i+3, ..... i+add -1
                int ret = dp[i][i + divpoint] + dp[i + divpoint][i + add] + nums[i] * nums[i + divpoint] * nums[i + add];
                if (dp[i][i + add] == 0)
                    dp[i][i + add] = ret;
                else
                    dp[i][i + add] = min(dp[i][i + add], ret);
            }
        }
    }

    answer = dp[0][nums.size() - 1];

    return answer;
}