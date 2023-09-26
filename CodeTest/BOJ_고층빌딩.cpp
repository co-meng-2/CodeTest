	#include <iostream>
	#define fastio std::ios_base::sync_with_stdio(false);\
	cin.tie(NULL);
	using std::cin;
	using std::cout;

	#include <vector>
	using std::vector;

	#include <cmath>
	using std::abs;

	// �� N��
	// ���� ������ ���� ���� �ٶ�
	// ���δ� : ���� ���� - � ���� �̾��� ��, �� ���� �ٸ� ������ ������ �ʴ´�.
	// ���ϸ� �� ��

	// ������ �� N 1 - 50
	// ���� 10�� ���� ����

	// ����
	// ���� ���� ���� ������ ���̴� �������� ���̴� ������ ��

	int N;

	int buildings[51]{};
	int ans[51]{};

	int main()
	{
		cin >> N;
		for (int i = 1; i <= N; ++i)
			cin >> buildings[i];

		// ���� ��
		for(int i = 1; i <=N; ++i)
		{
			// �ٸ� ��������
			for(int j = i+1; j <=N; ++j)
			{
				// �մ´�
				double slope = (buildings[i] - buildings[j]) / (double)(i - j);

				bool isMeet = false;

				// ������ �ٸ� �ǹ���� ����
				for(int k = i+1; k <= j-1; ++k)
				{
					// ���Ѵ�
					double height = buildings[i] + slope * (k - i);
					if(buildings[k] >= height)
					{
						isMeet = true;
						break;
					}
				}

				if(isMeet == false)
				{
					ans[i]++;
					ans[j]++;
				}
			}
		}

		int Max = -1;
		for (int i = 1; i <= N; ++i)
			Max = std::max(Max, ans[i]);

		cout << Max;

		return 0;
	}