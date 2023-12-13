#include <iostream>
#include <vector>
#include <algorithm> // std::lower_bound 사용

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> sum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> sum[i];
        sum[i] += sum[i - 1]; // 누적 합 계산
    }

    // 전체 합이 4로 나누어 떨어지지 않으면, 조건을 만족하는 방법이 없습니다.
    if (sum[N] % 4 != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long sumdiv4 = sum[N] / 4;
    long long sumdiv2 = sumdiv4 * 2;
    long long sumdiv4mul3 = sumdiv4 * 3;
    vector<int> vecDiv2Mark;
    vector<int> vecDiv4Mark;
    vector<int> vecMul3Mark;

    for (int i = 1; i < N; ++i) { // N 이전까지만 탐색해야 합니다.
        if (sum[i] == sumdiv2) vecDiv2Mark.push_back(i);
        if (sum[i] == sumdiv4) vecDiv4Mark.push_back(i);
        if (sum[i] == sumdiv4mul3) vecMul3Mark.push_back(i);
    }

    long long count = 0;

    for (int i : vecDiv2Mark) {

        auto it2 = upper_bound(vecMul3Mark.begin(), vecMul3Mark.end(), i);

		auto it3 = lower_bound(vecDiv4Mark.begin(), vecDiv4Mark.end(), i );
        --it3;

		if (it3 != vecDiv4Mark.end() && it2 != vecMul3Mark.end())
		{
			count += ((it3 - vecDiv4Mark.begin() + 1) * (vecMul3Mark.end() - it2));
            int debug = 1;
		}
    }

    cout << count << endl;
    return 0;
}