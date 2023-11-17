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

// 어떤 수열 요소의 합으로 어떤 수를 만들기
// sort하고 모든 수를 쓸지 안 쓸지를 정하는 dfs를 생성
// 작은 수 부터 쓴다.
// 근데 Wi가 2, 4, 8, 16, 32... 라고 가정하면 대충 10억까지 표현 가능함.. 따라서 dfs로는 불가능하다.

// 그렇다면 구간으로 생각해보자
// 만들 수 있는 수를 저장하려면 10억개의 공간이 필요하다. 이건 말이 안된다. 시간적으로나 메모리적으로나
// 그렇다면 구간을 저장하자.
// 모든 구간은 0 - x 이런식으로 설정되어 있다 그렇다면 우리는 x만 갈아치워주면 된다.
// 구간 최대 + 1 >= 다음 수 일 때 구간 최대 += 다음 수 이다. 
// ex) 구간 : 1 2 3 4 ..... 10000  /  다음 수 1000  ---> (10000 - 1000 + 1) + 1000 부터 (10000) + 1000 까지 만들 수 있는 범위의 수가 늘어난다.
// ex )구간 : 1 2 3 4 ..... 10000  /  다음 수 10002 ---> (10000 - 10002 + 1)이 음수이므로 구간의 다음 수를 만들 수 없다.

// S : 10:49
// U : 10:50
// T : 10:59
// C : 11:38
// Total : 49min