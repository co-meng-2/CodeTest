#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

void dfs(vector<int> nums, int maxDepth, int depth, int& cnt, bool& bExit, int sum = 0)
{
	if (bExit)
		return;

	if (depth == maxDepth)
	{
		if (sum > cnt)
			bExit = true;
		else if (sum == cnt)
			cnt++;

		return;
	}

	dfs(nums, maxDepth, depth + 1, cnt, bExit, sum);
	sum += nums[depth];
	dfs(nums, maxDepth, depth + 1, cnt, bExit, sum);
}

int main()
{
	fastio;

	int N;
	cin >> N;

	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	// std::sort(nums.begin(), nums.end(), std::greater<int>());

	//int cnt = 1;
	//bool bExit = false;
	//dfs(nums, N, 0, cnt, bExit);

	//cout << cnt;

	int lo = 0;
	int hi = 0;
	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < N; ++i)
	{
		if (hi + 1 >= nums[i] + lo)
		{
			hi += nums[i];
		}
		else
		{
			break;
		}
	}
	cout << hi + 1;

	return 0;
}

// N 1 - 1000
// Wi 1 - 1000000

// � ���� ����� ������ � ���� �����
// sort�ϰ� ��� ���� ���� �� ������ ���ϴ� dfs�� ����
// ���� �� ���� ����.
// �ٵ� Wi�� 2, 4, 8, 16, 32... ��� �����ϸ� ���� 10����� ǥ�� ������.. ���� dfs�δ� �Ұ����ϴ�.

// �׷��ٸ� �������� �����غ���
// ���� �� �ִ� ���� �����Ϸ��� 10�ﰳ�� ������ �ʿ��ϴ�. �̰� ���� �ȵȴ�. �ð������γ� �޸������γ�
// �׷��ٸ� ������ ��������.
// ��� ������ 0 - x �̷������� �����Ǿ� �ִ� �׷��ٸ� �츮�� x�� ����ġ���ָ� �ȴ�.
// ���� �ִ� + 1 >= ���� �� �� �� ���� �ִ� += ���� �� �̴�. 
// ex) ���� : 1 2 3 4 ..... 10000  /  ���� �� 1000  ---> (10000 - 1000 + 1) + 1000 ���� (10000) + 1000 ���� ���� �� �ִ� ������ ���� �þ��.
// ex )���� : 1 2 3 4 ..... 10000  /  ���� �� 10002 ---> (10000 - 10002 + 1)�� �����̹Ƿ� ������ ���� ���� ���� �� ����.

// S : 10:49
// U : 10:50
// T : 10:59
// C : 11:38
// Total : 49min