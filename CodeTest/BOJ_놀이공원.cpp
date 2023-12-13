#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// �̺�Ž������ ��� ����� �¿�� �ð��� ã�´�.
// �� �ð��� ��� �ִ� �¼��� ���ϰ�, �� �� �ð��� �¿� ����� ���� ���Ͽ� �ⱸ ��ȣ�� ã�´�.

int a(int b)
{
	if (b == 0)
		return 0;
	return a(b - 1);
}

int main()
{
	fastio;

	long long N, M;
	cin >> N >> M;

	vector<int> gigu(M);

	for (int i = 0; i < M; ++i)
	{
		cin >> gigu[i];
	}

	long long hi = 2'000'000'000LL * 30;
	long long lo = -1;

	while (lo + 1 < hi)
	{
		long long mid = (lo + hi) / 2;
		long long sum = 0;
		for (auto i : gigu)
		{
			sum += mid / i + 1;
		}
		if (sum >= N) hi = mid;
		else lo = mid;
	}
	
	long long lopeople = 0;
	if (lo != -1)
	{
		for (auto i : gigu)	
		{
			lopeople += lo / i + 1;
		}
	}

	long long diff = N - lopeople;
	
	vector<int> emptygigu;
	for (int i = 0; i < gigu.size(); ++i)
	{
		if (hi % gigu[i] == 0) emptygigu.push_back(i);
	}
	
	cout << emptygigu[diff - 1] + 1;
	a(10);
	return 0;
}


// S : 1:24
// U : 1:25
// T : 1:40
// C : 3:38
// Total : 2h �߰��� �ǰ��ؼ� ��