#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <algorithm>
using P = std::pair<int, int>;
// �� ���� N��
// ������ �� �ð��� �ɸ��� �ð� ���
// i��° ���� ó���ϴµ� Ti�ð� �ɸ��� Si�� ���� �� ó�� �ؾ���.
// �ִ��� �ʰ� �����ϴ� �ð��� �˾Ƴ�����
// 0�ú��� �����ص� ���� ����ĥ �� ���ٸ� -1

// ���� �ð��� ���� �������� �ֵ� ���� ������ ���� ������?

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