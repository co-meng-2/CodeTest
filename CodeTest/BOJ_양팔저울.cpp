#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

bool dp[15001];

int main()
{
	fastio;

	int N, M;
	cin >> N;
	vector<int> vecWeight(N);
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> vecWeight[i];
		sum += vecWeight[i];
	}

	cin >> M;
	vector<int> vecM(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> vecM[i];
	}
	dp[0] = true;

	for (int i = 0; i < N; ++i)
	{
		vector<int> nextTrue;
		for (int j = 0; j <= sum; ++j)
		{
			if (dp[j])
			{ 
				nextTrue.push_back(j + vecWeight[i]);
				nextTrue.push_back(abs(j - vecWeight[i]));
			}
		}
		for (auto ntrue : nextTrue)
		{
			dp[ntrue] = true;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		if (vecM[i] <= 15000 && dp[vecM[i]]) cout << "Y ";
		else cout << "N ";
	}

	

	return 0;
}

// ���� ���� N 30����
// ���� ���� 500 ����
// ���Ը� Ȯ���ϰ��� �ϴ� �� M
// M���� 40000����

// L R�� ���ؼ� L = R�̸� ���Ը� ���� �� �� ����
// Ȯ�� �߰� �ٸ� �߿� ������ ���� ����.

// �ߵ��� �ڿ��� �� ���� ��� ����� ���� ���Ѵ�.
// �׷��ٸ� �߸� �����ʿ� �ܴ�, ���ʿ� �ܴ�, ���� �ʴ´�. 3���� ����� ���� �ְ� �̴� ��� ��츦 Ž���ϴµ� 3^30�� ����

// S : 5:45
// U : 5:45
// T : 
// C :
// Total :