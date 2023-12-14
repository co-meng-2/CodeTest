#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <algorithm>

#include <queue>

// �� ������ο� ���Ͽ� �ִ��� �Ŷ���� �����ϴ� ������ Ǯ����� �ʳ�?
// ���� Ǯ�̴� 1-1 2-1 4-3 4-4�� ���� �ݷʰ� �߻�

// 1-1 2-2 3-3 4-100 4-100
// 1-1 2-2 3-3 7-100 7-100

// deadline - ramen
struct dr
{
	int d;
	int r;

	bool operator<(const dr& _rhs) const
	{
		return r < _rhs.r;
	}
};

// ���� ū deadline Ȯ��

int main()
{
	fastio;

	int N;
	cin >> N;

	vector<vector<int>> drs(N+1);

	int maxDeadline = 0;
	for (int i = 0; i < N; ++i)
	{
		int d, r;
		cin >> d >> r;
		drs[d].push_back(r);
		maxDeadline = std::max(maxDeadline, d);
	}

	std::priority_queue<dr> PQ;
	for (int i = 1; i <= N; ++i)
	{
		std::sort(drs[i].begin(), drs[i].end());
	}

	int curDeadline = maxDeadline;
	int sumRamen = 0;

	while (curDeadline)
	{
		if(!drs[curDeadline].empty())
			PQ.push({ curDeadline, drs[curDeadline].back() });

		if (!PQ.empty())
		{
			auto top = PQ.top();
			PQ.pop();
			
			sumRamen += top.r;
			drs[top.d].pop_back();
			if (!drs[top.d].empty())
				PQ.push({ top.d, drs[top.d].back() });
		}
		curDeadline--;
	}
	
	cout << sumRamen;
	return 0;
}


// S : 5:48
// U : 5:52
// T : 6:04
// C :
// Total :