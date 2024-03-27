#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int>& nums) {
    int answer = 0;

    int len = nums.size();
    // 자신 기준 왼쪽, 오른쪽에서 가장 큰 값 구함
    // 1. l > cur || r > cur

    const int INF = 1'000'000'001;
    // L, R Max
    vector<int> dp_f(len);
    dp_f[0] = INF;
    for (int i = 1; i < len; ++i)
    {
        dp_f[i] = min(dp_f[i - 1], nums[i - 1]);
    }

    vector<int> dp_b(len);
    dp_b[len - 1] = INF;
    for (int i = len - 2; i >= 0; --i)
    {
        dp_b[i] = min(nums[i + 1], dp_b[i + 1]);
    }

    for (int i = 1; i < len - 1; ++i)
    {
        if (dp_b[i] > nums[i] || dp_f[i] > nums[i])
        {
            answer++;
        }
    }

    answer += 2;
    return answer;
}

int main()
{
    int n;
	cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    solution(vec);
}