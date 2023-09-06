#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <algorithm>
using P = std::pair<int, int>;
// 할 일이 N개
// 끝내야 할 시간과 걸리는 시간 명단
// i번째 일은 처리하는데 Ti시간 걸리고 Si시 내에 일 처리 해야함.
// 최대한 늦게 시작하는 시간을 알아내야함
// 0시부터 시작해도 일을 끝마칠 수 없다면 -1

// 끝낼 시간이 가장 마지막인 애들 부터 끝내면 되지 않을까?

int N;
P arr[1001]{};

int main()
{
	fastio;

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i].second >> arr[i].first;

	std::sort(arr + 1, arr + N + 1, std::greater<P>());
	int MaxTime = 1000000;
	for (int i = 1; i <= N; ++i)
	{
		if (MaxTime > arr[i].first)
			MaxTime = arr[i].first;
		MaxTime -= arr[i].second;
	}

	if (MaxTime >= 0)
		cout << MaxTime;
	else
		cout << -1;
}