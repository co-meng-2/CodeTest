#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 10�� �Ÿ� -> ���� �̺�Ž�� �����
// �ִ� �Ÿ��� mid��� �ϸ� TTTTTFFFFFF�̷������� ���� ��
// 1 + (n-1)*mid�� 10���� �ʰ����� ������ T�� ������ ������ �ɵ�?
// �ٵ� ���� ��ǥ�� �����Ǿ� ����
// �׷��ٸ� �Ÿ��� ���� �׻� TTTFF�̷������� ������?
// 1 2 4 8 9 ���� 3���� ���� �� ������ 1 5 9 �� 4������ ����� 1 4 9�� 3�̴�.
// �׷��� ���� ���� ��ġ���� �����ؼ� ���� ��ġ�� �ٸ鼭 �Ÿ����� ���ų� ūä�� ��� �����⸦ ���� true�� �ϸ� ���� ������?

bool check(int C ,int dist, vector<int>& locations)
{
	int s = 0;
	int d = 1;
	while (true)
	{
		if (d >= locations.size())
			return false;

		if (locations[d] - locations[s] >= dist)
		{
			s = d;
			d++;
			C--;
			if (C == 0)
				return true;
		}
		else
		{
			d++;
		}
	}
}

int main()
{
	fastio;

	int N, C;
	cin >> N >> C;

	vector<int> locations(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> locations[i];
	}
	std::sort(locations.begin(), locations.end());
	
	// BAD
	// int lo = locations.front();
	// int hi = locations.back() + 1;
	// lo = 5000 hi = 5004�� ��츦 �����غ���
	
	int lo = 1;
	int hi = locations.back() - locations.front() + 1;

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		
		if (check(C - 1, mid, locations))
			lo = mid;
		else
			hi = mid;
	}

	cout << lo;

	return 0;
}


// S : 2:09
// U : 2:11
// T : 2:23
// C : 2:51
// Total :