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

// 월드컵 결과가 가능한가?

// 승 무승부 패 순서 6국가

// 문제
// 가능한 결과 1 불가능한 결과 0 출력
// 총 4개의 케이스

// 경기의 합 -> 모든 나라가 같아야 함
// 승의 합 -> 패와 같아야 함
// 패의 합 -> 승과 같아야 함
// 무의 합 -> 0 >= 무 이면 더하고, 아니면 뺴고 이걸로 안되네

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

	// one 이김
	score[one].win++;
	score[two].lose++;
	if(countries[one].win >= score[one].win && countries[two].lose >= score[two].lose )
		dfs(depth + 1);
	score[one].win--;
	score[two].lose--;

	// two 이김
	score[one].lose++;
	score[two].win++;
	if (countries[one].lose >= score[one].lose && countries[two].win >= score[two].win )
		dfs(depth + 1);
	score[one].lose--;
	score[two].win--;

	// 비김
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

		// 경기 수 체크
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

