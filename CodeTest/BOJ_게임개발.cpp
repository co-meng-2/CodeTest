#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// ����
// ��� �ǹ��� ���µ� �Ÿ��� �ּ��� �ð�
// �ǹ��� ��������� �ִ�

// �Է�
// n �ǹ��� ������
// �ð� �ǹ��� ���� ���� ���� ���������ϴ� �ǹ����� ��ȣ
// �� ���� -1�� ����
// ���� ���� �ǹ��� ���ÿ� ���� �� �ִ�.

// �ɸ��� �ð��� 100,000 ���� �ڿ���

// Ǯ��
// ���� ��� �Ǵ� �ǹ� �� ����
// ���� �ɸ��� �ֵ��� ���� ������ ����.
// �ٵ� ���ÿ� ���� �� �����ϱ� �׳� ������� ������ �� ��?
// ������ �ֵ��� ���´�.

struct tInfo
{
	vector<int> next;
	vector<int> neces;
	int time;
	int startTime = -1;

	bool operator>(const tInfo& _rhs) const
	{
		return startTime < _rhs.startTime;
	}
};

vector<tInfo> buildings;

void downSearch(int idx)
{
	if (buildings[idx].startTime == 0) return;

	int Max = -1;
	for(auto neces : buildings[idx].neces )
	{
		if (buildings[neces].startTime == -1)
			downSearch(neces);
		Max = std::max(Max, buildings[neces].startTime + buildings[neces].time);
	}
	buildings[idx].startTime = Max;
}

int main()
{
	int buildingCnt;
	cin >> buildingCnt;
	buildings.resize(buildingCnt+1);

	for(int i = 1; i <= buildingCnt; ++i)
	{
		int time;
		cin >> time;
		buildings[i].time = time;

		while(true)
		{
			int neces;
			cin >> neces;
			if (neces == -1)
			{
				if(buildings[i].neces.empty()) 	buildings[i].startTime = 0;
				break;
			}

			buildings[i].neces.push_back(neces);
			buildings[neces].next.push_back(i);
		}
	}

	for(int i = 1; i <= buildingCnt; ++i)
	{
		if(buildings[i].next.empty())
		{
			downSearch(i);
		}
	}

	for(int i = 1; i <= buildingCnt; ++i)
	{
		cout << buildings[i].time + buildings[i].startTime << "\n";
	}

	return 0;
}

// U : 4:34 - 4:36	2min
// T : 4:43			7min
// C : 5:52			1:09min
// T :				78min