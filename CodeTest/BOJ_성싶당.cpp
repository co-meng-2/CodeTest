#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 밀키트 N개의 재료
// i번째 재료는 Li의 유통기한 Si의 부패기한
// 구매 후 x일에 i번째 재료에 있는 세균수는 max Si*(1, x-Li)
// 모든 세균수의 합이 G마리 이하면 먹을 수 있다.
// 최대 K개 빼서 세균수가 G마리 이하면 먹음
// 중요한 재료는 뺄 수 없음
// 산날부터 며칠 후 부터 먹을 수 있을까?

// bs -> 날짜를 hi lo로
// 각 성분에 대한 최대 날짜 구함
// 중요도 1인 애들 모아서 정렬 후 작은 날짜부터 뺌
// 중요도 1 0 합쳐서 min을 구함.
// 근데 모든 재료 세균합임

int N, G, K;
struct tInfo
{
	int s;
	int l;
	int o;
};
tInfo arr[200001]{};
int subCnt = 0;

// 상했으면 false 아니면 true
bool check(int day)
{
	static vector<long long> vecSub(subCnt, 0);
	long long sum = 0;
	int idx = 0;
	for (int i = 1; i <= N; ++i)
	{
		long long tmp = arr[i].s * (long long)std::max(day - arr[i].l, 1);
		sum += tmp;
		if (arr[i].o == 1)
		{
			vecSub[idx] = tmp;
			idx++;
		}
	}

	if (sum <= G) return true;

	std::sort(vecSub.begin(), vecSub.end(), std::greater<long long>());
	for (int i = 0; i < K; ++i)
	{
		if( i < vecSub.size())
			sum -= vecSub[i];
	}

	if (sum <= G) return true;
	return false;
}

int main()
{
	fastio;
	cin >> N >> G >> K;

	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i].s >> arr[i].l >> arr[i].o;
		if (arr[i].o == 1) subCnt++;
	}

	
	long long lo = 0;
	long long hi = 2'000'000'001;

	while (lo + 1 < hi)
	{
		long long mid = (lo + hi) / 2;
		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}

	cout << lo;

	return 0;
}