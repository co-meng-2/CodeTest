#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// 적당한 수 e
// e 이하의 임의의 수 s
// s를 여러개 제시
// 각 s에 대해서 s <= k <= e 일 때, 모든 k에 대해 가장 많이 등장한 수
// 가장 많이 등장한 수가 여러개 -> 그중 가장 작은 수

// 문제
// 각 s에 대한 가장 많이 등장한 수

// 조건
// 1 <= e <= 5,000,000
// 1 <= s <= e
// s 길이 -> 1 ~ 100'000

// 풀이


vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;

    // dp[i] -> i번째 숫자가 몇개 있는지
    int dp[5'000'001]{};

    // dp 갱신
    for (int num = 1; num <= 5'000'000; ++num)
        for (int mul = 5'000'000 / num; mul >= 1; mul--)
            dp[num * mul]++;

    // dp[k]-> e~e부터 생각하며, k~e부터 최댓값을 가진 숫자가 뭔지
    int dp2[5'000'001]{};
    dp2[e] = e;
    for (int i = e - 1; i >= 1; --i)
        dp2[i] = dp[dp2[i + 1]] > dp[i] ? dp2[i + 1] : i;

    for (auto start : starts)
        answer.push_back(dp2[start]);

    return answer;
}

// U : 12min
// T : 50min
// C : lh
// Total : 2h2min