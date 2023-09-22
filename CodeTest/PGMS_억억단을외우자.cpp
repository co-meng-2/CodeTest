#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ������ �� e
// e ������ ������ �� s
// s�� ������ ����
// �� s�� ���ؼ� s <= k <= e �� ��, ��� k�� ���� ���� ���� ������ ��
// ���� ���� ������ ���� ������ -> ���� ���� ���� ��

// ����
// �� s�� ���� ���� ���� ������ ��

// ����
// 1 <= e <= 5,000,000
// 1 <= s <= e
// s ���� -> 1 ~ 100'000

// Ǯ��


vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;

    // dp[i] -> i��° ���ڰ� � �ִ���
    int dp[5'000'001]{};

    // dp ����
    for (int num = 1; num <= 5'000'000; ++num)
        for (int mul = 5'000'000 / num; mul >= 1; mul--)
            dp[num * mul]++;

    // dp[k]-> e~e���� �����ϸ�, k~e���� �ִ��� ���� ���ڰ� ����
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