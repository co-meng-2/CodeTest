#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// ��ŰƮ N���� ���
// i��° ���� Li�� ������� Si�� ���б���
// ���� �� x�Ͽ� i��° ��ῡ �ִ� ���ռ��� max Si*(1, x-Li)
// ��� ���ռ��� ���� G���� ���ϸ� ���� �� �ִ�.
// �ִ� K�� ���� ���ռ��� G���� ���ϸ� ����
// �߿��� ���� �� �� ����
// �곯���� ��ĥ �� ���� ���� �� ������?

// bs -> ��¥�� hi lo��
// �� ���п� ���� �ִ� ��¥ ����
// �߿䵵 1�� �ֵ� ��Ƽ� ���� �� ���� ��¥���� ��
// �߿䵵 1 0 ���ļ� min�� ����.
// �ٵ� ��� ��� ��������

int N, G, K;
struct tInfo
{
	int s;
	int l;
	int o;
};
tInfo arr[200001]{};
int subCnt = 0;

// �������� false �ƴϸ� true
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