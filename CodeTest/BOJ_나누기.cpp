#include <iostream>
#include <vector>
#include <algorithm> // std::lower_bound ���

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> sum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> sum[i];
        sum[i] += sum[i - 1]; // ���� �� ���
    }

    // ��ü ���� 4�� ������ �������� ������, ������ �����ϴ� ����� �����ϴ�.
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

    for (int i = 1; i < N; ++i) { // N ���������� Ž���ؾ� �մϴ�.
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