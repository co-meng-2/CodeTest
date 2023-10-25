#include <iostream>
#include <vector>

using namespace std;

vector<long long> countDigits(long long n) {
    vector<long long> counts(10, 0);

    // 자릿수
    long long factor = 1;

    while (n >= factor) {

        // ex) N = 4567  factor = 2

        // 현재 자릿수 밑의 숫자들 ex) 7
        long long lowerNum = n % factor;

        // 현재 자릿수의 숫자 ex) 6
        long long currentDigit = (n / factor) % 10;

        // 현재 자릿수 위의 숫자들 ex) 45
        long long higherNum = n / (factor * 10);

        // 각 자릿수에 0 ~ 9을 넣어보고 경우에 따라 각 자리수의 Count를 늘려줌.
        for (int i = 0; i < 10; ++i) {

            // 최고 자릿수에서 앞 자리가 0인 경우는 없음
            if (higherNum == 0 && i == 0) continue;

            // 넣을 숫자 i가 현재 자리 숫자보다 작은 경우
            if (i < currentDigit) 
            {
                // i가 0인 경우 higherNum은 0이 될 수 없다. ex) 자릿수가 1인 경우 0에 higherNum이 0이면 전체 숫자는 0이므로 불가능
                //                                          ex) 자릿수가 > 1인 경우 000n 이런식으로 숫자가 나오게 된다. 이는 사실 n이다. 따라서 counts[i]를 늘려선 안된다.
                if (i == 0)
                    counts[i] += higherNum * factor;
                // higherNum에 가능한 숫자 * lowerNum에 가능한 숫자
                else
                    counts[i] += (higherNum + 1) * factor;
            }
            else if (i == currentDigit) 
            {
                // i가 0인 경우에는 위와 같이 higherNum에 0이 들어올 수 없으므로 1을 빼주어야 한다. 
                if(i == 0)
                    counts[i] += (higherNum - 1) * factor + lowerNum + 1;
                // higherNum에 가능한 숫자 * lowerNum에 가능한 숫자
                else
                    counts[i] += higherNum * factor + lowerNum + 1;
                
            }
            else 
            {
                // higherNum에 가능한 숫자 * lowerNum에 가능한 숫자
                counts[i] += higherNum * factor;
            }
        }

        factor *= 10;
    }
    return counts;
}

int main() {
    long long N;
    cin >> N;

    vector<long long> counts = countDigits(N);

    for (int i = 0; i < 10; i++) {
        cout << counts[i] << " ";
    }
    return 0;
}
