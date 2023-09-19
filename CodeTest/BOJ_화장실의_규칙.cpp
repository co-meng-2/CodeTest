#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <queue>
using std::queue;
using std::priority_queue;

// N���� ����� ���
// ��ī�� K+1������ ���� ����.
// M���� �ٷ� ������ ���
// 1��° 1��° �� 2��° 2��°��.... M+1��° 1��° ��
// M���� �� �� ���ο��� �ٹ� �ϼ��� ���� ���ΰ� ȭ��� �̿�
// �ٹ� �ϼ� �����ϸ� ���� ������ ���� ���ΰ� ȭ��� �̿�
// �� ���ٸ�, �� ��ȣ�� ���� ���� ���� �̿�


// ��� ����� ��	N 1 - 10e5
// ���� ��			M 2 - 10e5
// �ڽ��� �տ� ���ִ� ����� �� K 0 - N-1
// Di, Hi�� ������� �־���

// ����
// ��ī�� ȭ��� �̿��ϱ� �� �� ���� ����� ȭ����� �̿��ϴ��� ���϶�!

// Ǯ��
// vector<queue<>>�� ����� �� ���� �� ��, ���� �켱������ ���� �ָ� ����.
// M*N ->  1������ ���ִ� ��� ������ �ȴ�. (100000 * 100001 / 2)
// ���� �� �ֵ鸸 ���� ���� priority_queue�� �ϳ� �����.
// pop front�ϰ�, ���� ���� �ٿ��� �ٽ� ������ �߰����ش�.
// ��ī�� ť������ ������ ����Ѵ�.
// ��ī�� priority_queue���� ���� �� �տ� ���� ����� ���� ����.
// NlogN

int N, M, K;

struct tHDM
{
	int D;
	int H;
	int M;

	bool operator<(const tHDM& _rhs) const
	{
		bool bd = D == _rhs.D;
		bool bh = H == _rhs.H;
		if (bd && bh)
			return M > _rhs.M;
		else if (bd)
			return H < _rhs.H;
		else
			return D < _rhs.D;
	}
};



int main()
{
	cin >> N >> M >> K;

	vector<queue<tHDM>> HDM(M+1);

	// ���⼭ ���� -> deca�� K+1��° ������, ���� �ε����� �̿��� Col�� Row�� �����ϰ� �����Ƿ� (K+1)�� ����ϸ� �ȵȴ�.
	int decaCol = K / M + 1;
	int decaRow = K % M + 1;

	// make queueHDM
	for(int i = 0; i < N; ++i)
	{
		int d, h;
		cin >> d >> h;
		int m = i % M + 1;
		HDM[m].push({ d, h, m });
	}

	priority_queue<tHDM> PQ;


	// �ʱ� PQ
	for(int i = 1; i < HDM.size(); ++i)
	{
		if (HDM[i].empty()) continue;
		PQ.push(HDM[i].front());
		HDM[i].pop();
	}

	int cnt = 0;
	int decaColCnt = 1;
	while(true)
	{
		auto top = PQ.top();
		PQ.pop();
		if (top.M == decaRow)
		{
			if (decaColCnt == decaCol)
				break;
			else
				decaColCnt++;
		}
		cnt++;

		if (HDM[top.M].empty()) continue;
		PQ.push(HDM[top.M].front());
		HDM[top.M].pop();
	}

	cout << cnt;

	return 0;
}

// 48��