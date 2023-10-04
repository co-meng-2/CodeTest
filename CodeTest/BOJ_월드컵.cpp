#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)

using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <set>
using std::set;
using std::multiset;

// ������ ����� �����Ѱ�?

// �� ���º� �� ���� 6����

// ����
// ������ ��� 1 �Ұ����� ��� 0 ���
// �� 4���� ���̽�

// ����� �� -> ��� ���� ���ƾ� ��
// ���� �� -> �п� ���ƾ� ��
// ���� �� -> �°� ���ƾ� ��
// ���� �� -> 0 >= �� �̸� ���ϰ�, �ƴϸ� ���� �̰ɷ� �ȵǳ�

struct tScore
{
	int win;
	int draw;
	int lose;
	int sum;
};

tScore countries[6]{};

struct tDepthMatch
{
	int one;
	int two;
};

vector<tDepthMatch> vecDepthMatch;
tScore score[6]{};
bool isValid = false;
void dfs(int depth)
{
	if(depth == vecDepthMatch.size())
	{
		isValid = true;
		return;
	}

	int one = vecDepthMatch[depth].one;
	int two = vecDepthMatch[depth].two;

	// one �̱�
	score[one].win++;
	score[two].lose++;
	if(countries[one].win >= score[one].win && countries[two].lose >= score[two].lose )
		dfs(depth + 1);
	score[one].win--;
	score[two].lose--;

	// two �̱�
	score[one].lose++;
	score[two].win++;
	if (countries[one].lose >= score[one].lose && countries[two].win >= score[two].win )
		dfs(depth + 1);
	score[one].lose--;
	score[two].win--;

	// ���
	score[one].draw++;
	score[two].draw++;
	if (countries[one].draw >= score[one].draw && countries[two].draw >= score[two].draw )
		dfs(depth + 1);
	score[one].draw--;
	score[two].draw--;
}

int main()
{
	for(int i = 0; i < 6; ++i)
		for(int j = i + 1 ; j < 6; ++j)
			vecDepthMatch.push_back({i, j});

	int caseCnt = 4;
	int countryCnt = 6;

	vector<int> vecAns;
	for(int i = 0; i < caseCnt; ++i)
	{
		for (int j = 0; j < countryCnt; ++j)
		{
			cin >> countries[j].win >> countries[j].draw >> countries[j].lose;
			countries[j].sum = countries[j].win + countries[j].draw + countries[j].lose;
		}

		// ��� �� üũ
		bool bContinue = false;
		for (int j = 0; j < countryCnt; ++j)
			if(countries[j].sum != 5)
			{
				vecAns.push_back(0);
				bContinue = true;
				break;
			}
		if (bContinue) continue;

		isValid = false;
		dfs(0);

		if(isValid == false)
		{
			vecAns.push_back(0);
			continue;
		}

		vecAns.push_back(1);
	}

	for (int i = 0; i < vecAns.size(); ++i)
		cout << vecAns[i] << " ";

	return 0;
}

