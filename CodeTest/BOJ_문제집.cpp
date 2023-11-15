#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>

// ���� Ǫ�� ���� ���� ������ ����
// �����ϸ� ���� ��������

// N ������ �� 1 - 32000
// M ���� Ǯ�� ���� �� 1- 100000

// 3 -1 , 2 - 1�� ��� 2�� ���� Ǯ��� ��
// ���� �׷��� �� �ֻ���� ���� ���� ���� ���� ���� �׷����� ����
// �� �׷����� ���� ���ϴ�(level�� �������� �켱������ ����)�� ���� �� ���� ���� ����

// �ֻ���� �θ� ������ ��������
// ���ϴ��� �ڽ��� ������ ���� ����.
// ���ϴܵ��� Q�� �־���� ���� ���� �� ���� pop�ϸ� �θ� �ر� ������ ������ �� Q�� push 

struct tInfo
{
	int cur = -1;
	vector<int> parents;
	vector<int> childs;
	bool checked = false;
};

int main()
{
	fastio;

	int N, M;
	cin >> N >> M;

	// 1���� �����ϴ� �������� �ε���
	// ���� Ǯ����ϴ� ����(child) �ش� ������ Ǭ ���� Ǯ �� �ִ� ����(parent)�� ������ ����ü tInfo 
	vector<tInfo> infos(N + 1);

	// �Է��� �ڷ�ȭ ��Ų��.
	for (int i = 0; i < M; ++i)
	{
		int next, prev;
		cin >> prev >> next;

		infos[prev].cur = prev;
		infos[prev].parents.push_back(next);
		infos[next].cur = next;
		infos[next].childs.push_back(prev);
	}

	// PQ�� �̿��� ���� �Էµ� �� ���� ���� �ε����� ���� ������ top�� �ǰԲ� �Ѵ�.
	// �ڽ��� ���� leaf�� ��, ���� ���� �ذ��ؾ��ϴ� �������� �켱������ PQ�� �ִ´�.
	std::priority_queue<int, vector<int>, std::greater<>> PQ;
	for (int i = 1; i <= N; ++i)
	{
		if (infos[i].childs.empty())
			PQ.push(i);
	}

	// ����� ����
	vector<int> ansOrder;

	// 
	while (!PQ.empty())
	{
		auto top = PQ.top();
		PQ.pop();
		// checked�� ������ Ǯ�ȴ��� Ȯ��
		infos[top].checked = true;
		// ��� ���Ϳ� ���� ���� �־���
		ansOrder.push_back(top);

		// �ذ��� ������ �θ�, ���� ������ �ٽ� PQ�� �־��ֱ� ���� �� ������ Ǯ �� �ִ��� Ȯ��.
		for (auto parentIdx : infos[top].parents)
		{
			bool allChecked = true;
			// ��� ���� �������� Ǯ�ȴ°�(checked)?
			for (auto childIdx : infos[parentIdx].childs)
				if (infos[childIdx].checked == false)
				{
					allChecked = false;
					break;
				}

			// �� Ǯ���ִٸ� ���� ������ �־���
			if (allChecked)
				PQ.push(parentIdx);
		}
	}

	// ���� ���
	for (auto order : ansOrder)
		cout << order << " ";

	return 0;
}


// S : 1050
// U : 1051
// T : 1116
// C : 1141
// Total : 51