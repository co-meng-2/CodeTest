#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <string>
#include <climits>

// ���丮���� �� �� ����! (N+M)!/N!/M! �������� ������ ���丮�󿡼� �����÷ο찡 �߻������Ͽ� ��������� ���� ���鸸 ���� �� ����.
long long Factorial(int n, long long res = 1)
{
	if (res > (1LL << 63 - 1LL) / 100LL) 
		return 0;
	if (n == 1) return res;
	return Factorial(n-1, res * n);
}

int main()
{
	fastio;

	int N, M, K;
	cin >> N >> M >> K;

	long long dp[101][101]{};

	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 1;
			else
			{
				// ���� �� ��� + �����÷ο� ���� ( 10�� �̻� �������� �˸� ��. )
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				if (dp[i][j] > 1000000000) dp[i][j] = 1000000001;
			}
		}
	}

	if (dp[N][M] < K)
	{
		cout << -1;
		return 0;
	}
	
	std::string ans = "";


	int prevSum = 0;

	// ���� ����
	while (true)
	{
		// A�����ϴ� ���
		long long selectA = prevSum + dp[N-1][M];

		if (selectA >= K)
		{
			ans.push_back('a');
			N--;
		}
		// Z�� �����ϴ� ���
		else
		{
			// �������� �� ������ �и��� ������ A������ ������ �������ش�.
			prevSum = selectA;
			ans.push_back('z');
			M--;
		}

		// A�� Z�� �ϳ��� �� ���� �� �������� ä���ش�.
		if (N == 0)
		{
			while (M--)
			{
				ans.push_back('z');
			}
			break;
		}
		else if (M == 0)
		{
			while (N--)
			{
				ans.push_back('a');
			}
			break;
		}
			
	}

	for (auto it : ans)
	{
		cout << it;
	}
	

	return 0;
}


// S : 3:56
// U : 4:00
// T : 4:30
// C : 6:01
// Total : 1h 30