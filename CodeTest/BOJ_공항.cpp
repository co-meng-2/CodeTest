#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// �Ʒ����� ä��� -> 2 1�� ��쿡�� ������ ä���� ��.
// ������ ä���� �Ѵ�.
// ������ ä���� �� visited�� �����Ѵ�?
// �־��� ��� -> 1 + 2 + 3 + ... 100000 = 50�� ����

// 10 9 8 6 3 2 �̷��� ä���� ���¶�� ����.

// dp[i]�� ���� ���� ����
// gi�� ���� -> dp[gi] ���� �޾ƺ� dp[gi] ���� ������ �ƴ϶�� �� ������ dp�� �ٽ� �޾� ���� ������ Ž�� + dp[gi]�� �̾��� ������ �������ش�.
// ����(�����ִٸ�)��� �� ��(--) �������� ���� ����.

const int isOpen = -1;
const int isEnd = -2;

// �����ִ� ���� Gate�� ��������� ã�´�. ã�� ���� Gate�� �ε����� return �Ѵ�.
int FindNextGate(int desireMaxGateIdx, vector<int>& dp, int& ans, bool& bExit)
{
	// ���������� ������ Gate�� �������� -> ���
	if (dp[desireMaxGateIdx] == isEnd)
	{
		bExit = true;
		return isEnd;
	}

	// ���������� ������ Gate�� �������� 
	else if (dp[desireMaxGateIdx] == isOpen)
	{
		ans++;
		// ������ �ε����� 1 -> ���� �ε����� ����.
		if (desireMaxGateIdx == 1)
			return dp[desireMaxGateIdx] = isEnd;
		/// ������ �ε����� 1�� �ƴϸ� ������ �ε������� 1�� ���� ���� dp�� ä���ش�.
		else
			return dp[desireMaxGateIdx] = desireMaxGateIdx - 1;
	}

	// dp�� ��� �ִ� ���� Gate�� ���� �����ϱ�.
	else if (dp[desireMaxGateIdx] > 0)
	{
		dp[desireMaxGateIdx] = FindNextGate(dp[desireMaxGateIdx], dp, ans, bExit);
		return dp[desireMaxGateIdx];
	}
}

int main()
{
	fastio;

	int G, P;
	cin >> G >> P;

	// ����Ⱑ ������ �ϴ� ���� ū Gate
	vector<int> desireGateIdx(P+1);
	for (int i = 1; i <= P; ++i)
	{
		cin >> desireGateIdx[i];
	}

	// dp[i]�� desireGateIdx[i]���忡�� �����ִٰ� �����Ǵ� ���� Gate.
	vector<int> dp(G + 1, -1);
	int ans = 0;		// ��� ����
	bool bExit = false; // ���� ��� bool
	for (int i = 1; i <= P; ++i)
	{
		FindNextGate(desireGateIdx[i], dp, ans, bExit);
		if(bExit)
			break;
	}

	cout << ans;

	return 0;
}

// S : 10:37
// U : 10:41
// T : 10:54
// C : 11:21
// Total : 44 min