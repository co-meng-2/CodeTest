#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <cmath>
#include <algorithm>

// ����
// X,Y���� 0,0���� ���� ��
// �ɾ �� -> 1�ʿ� 1��ŭ
// ���� -> T�ʿ� D��ŭ ����������, ��Ȯ�ϰ� D��ŭ��
// �ð��� �ּڰ���?

// �밢������ ���°� ������ ����
// �Ѿ�� ���ƿ��°� �� ���� �� �� ����
// �ϴ� �ִ��� �ٱ�� �Ÿ��� ����
// �Ѿ�� ���� �� �Ѿ�� ��� ���

int main()
{
	cout.precision(20);
	int X, Y, D, T;

	cin >> X >> Y >> D >> T;
	vector<double> vecAns;

	double dist = std::sqrt(X * X + Y * Y);
	if (D <= T)
	{
		cout << dist;
		return 0;
	}

	double ansN = 0;

	// ���� �ɶ����� ����
	int cnt = 0;
	while(dist > 0)
	{
		dist -= D;
		ansN += T;
		cnt++;
	}

	// ������ ����ؼ� ���η��� ������� ����
	if (cnt >= 2)
		vecAns.push_back(ansN);
	else
		vecAns.push_back(ansN + T);

	// �����ϰ� �ڵ��� �ɾ����
	vecAns.push_back(ansN - dist);

	// �����ϰ� �ɾ����
	double ansP = ansN - T;
	double distP = dist + D;
	vecAns.push_back(ansP + distP);

	std::sort(vecAns.begin(), vecAns.end());
	cout << vecAns[0];

	return 0;
}

// U : 3:46 - 3:47  1min
// T : 3:46 - 3:58  12min (�밢���� ���� ����)
// C : 4:32			34min
// T : 45min