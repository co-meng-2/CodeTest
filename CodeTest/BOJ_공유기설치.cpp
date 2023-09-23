#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// ��𼭳� �������� -> ������ C��
// �� ������ ������ �ϳ��� ��ġ ����
// ���� ������ �� ������ ������ �Ÿ� ������ ũ��

// ����
// ���� ���� N  2 - 200,000
// �������� ���� C 2 - N
// ���� ��ǥ xi 0 - 10��
// ���� ������ �� ������ ������ �ִ� �Ÿ�

// Ǯ��
// 2���� �� ��
// 3���� �� ���� �߰�
// 4���� ��������

// ������ hi lo�� ���Ѵ�?
// check�� ���� �ִ� ���� MaxK�� ���� ����?

int N, C;
int arr[200001]{};

bool check(int interval)
{
	int idx = 1;
	for(int i = 0; i < C; ++i)
	{
		int acc = 0;
		while(true)
		{
			idx++;
			if (idx > N)
				return false;
			acc += arr[idx] - arr[idx - 1];
			if (acc >= interval) break;
		}
	}
	return true;
}

int main()
{
	fastio;
	cin >> N >> C;

	for(int i = 1; i <= N; ++i)
		cin >> arr[i];

	std::sort(arr + 1, arr + N + 1);

	// ���� �տ� ��ġ�Ǿ� �ִٰ� ����
	C -= 1;

	int lo = 1;
	int hi = 1'000'000'001;

	while(lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid) == check(lo)) // true
			lo = mid;
		else
			hi = mid;
	}

	cout << lo;

	return 0;
}

