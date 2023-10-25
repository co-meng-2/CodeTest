#include <iostream>
#include <vector>

using namespace std;

vector<long long> countDigits(long long n) {
    vector<long long> counts(10, 0);

    // �ڸ���
    long long factor = 1;

    while (n >= factor) {

        // ex) N = 4567  factor = 2

        // ���� �ڸ��� ���� ���ڵ� ex) 7
        long long lowerNum = n % factor;

        // ���� �ڸ����� ���� ex) 6
        long long currentDigit = (n / factor) % 10;

        // ���� �ڸ��� ���� ���ڵ� ex) 45
        long long higherNum = n / (factor * 10);

        // �� �ڸ����� 0 ~ 9�� �־�� ��쿡 ���� �� �ڸ����� Count�� �÷���.
        for (int i = 0; i < 10; ++i) {

            // �ְ� �ڸ������� �� �ڸ��� 0�� ���� ����
            if (higherNum == 0 && i == 0) continue;

            // ���� ���� i�� ���� �ڸ� ���ں��� ���� ���
            if (i < currentDigit) 
            {
                // i�� 0�� ��� higherNum�� 0�� �� �� ����. ex) �ڸ����� 1�� ��� 0�� higherNum�� 0�̸� ��ü ���ڴ� 0�̹Ƿ� �Ұ���
                //                                          ex) �ڸ����� > 1�� ��� 000n �̷������� ���ڰ� ������ �ȴ�. �̴� ��� n�̴�. ���� counts[i]�� �÷��� �ȵȴ�.
                if (i == 0)
                    counts[i] += higherNum * factor;
                // higherNum�� ������ ���� * lowerNum�� ������ ����
                else
                    counts[i] += (higherNum + 1) * factor;
            }
            else if (i == currentDigit) 
            {
                // i�� 0�� ��쿡�� ���� ���� higherNum�� 0�� ���� �� �����Ƿ� 1�� ���־�� �Ѵ�. 
                if(i == 0)
                    counts[i] += (higherNum - 1) * factor + lowerNum + 1;
                // higherNum�� ������ ���� * lowerNum�� ������ ����
                else
                    counts[i] += higherNum * factor + lowerNum + 1;
                
            }
            else 
            {
                // higherNum�� ������ ���� * lowerNum�� ������ ����
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
