#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int,int,int>;

// 몇 자리 수를 만들 수 있나 기록
// 어떻게?
// 자기 인덱스보다 뒤에 있는 숫자들 중에 가장 작은 갯수를 가진 수 중 가장 작은 수가 만들 수 있는 자릿수

// 가장 작은 자릿수를 만들 수 있는 숫자를 찾음
// 그 수가 가리키는 가장 작은 갯수 중 가장 작은 수로 들어감
// 다시 그 숫자가 가리키는 가장 작은 갯수 중 가장 작은 수로

// 가장 작은 수의 갯수가 0일 경우 그 숫자를 마지막으로 넣어줌

// 시작이 0이면?
// 시작을 1부터 9로 잡음
// 이거 안 됨 -> 가장 작은 수의 갯수가 자릿수를 보장 X 123456789011223344556677889900

// 처음 1 ~ 9 brute하게 진행하면서 1 ~ 9 구간의 갯수 셈
// 구간 수 가장 작으면서 가장 작은 수를 구함
// 구간 수 만큼 0 추가
// 구간 뒤에서 없는 숫자 중 가장 작은 수를 넣어줌
// 당연히도 안 된다~



int main()
{
	fastio;

	string str;
	cin >> str;

	vector<vector<int>> infos(10);

	for(int i = 0; i < str.size(); ++i)
		infos[str[i] - '0'].push_back(i);

	vector<int> sections(str.size());

	vector<bool> visited(10, false);
	int curCnt = 0;
	int sectionCnt = 0;

	vector<int> firsts(10, -1);
	for(int i = str.size() -1; i >= 0; --i)
	{
		sections[i] = sectionCnt;

		firsts[str[i] - '0'] = i;
		if (!visited[str[i] - '0'])
		{
			visited[str[i] - '0'] = true;
			curCnt++;

			if (curCnt == 10)
			{
				sectionCnt++;
				curCnt = 0;
				fill(visited.begin(), visited.end(), false);
			}
		}

		
	}

	int mnIdx = firsts[1];
	for(int i = 1; i < 10; ++i)
	{
		if(firsts[i] == -1)
		{
			cout << i;
			return 0;
		}

		if (sections[firsts[i]] < sections[mnIdx])
			mnIdx = firsts[i];
	}

	string ans;
	int numCnt = sections[mnIdx] + 2;
	ans += str[mnIdx];
	numCnt--;

	int s = mnIdx;
	while(s < str.size() && numCnt > 1)
	{
		int curNum = str[s] - '0';

		for(int i = 0; i < 10; ++i)
		{
			int cmpIdx = infos[i][upper_bound(infos[i].begin(), infos[i].end(), s) - infos[i].begin()];
			if(sections[cmpIdx] < numCnt - 1)
			{
				ans += str[cmpIdx];
				numCnt--;
				s = cmpIdx;
				break;
			}
		}
	}

	fill(visited.begin(), visited.end(), false);
	for(int i = s + 1; i < str.size(); ++i)
	{
		visited[str[i] - '0'] = true;
	}

	for(int i = 0; i < 10; ++i)
		if(visited[i] == false)
		{
			ans += (i + '0');
			break;
		}

	// 4개의 섹션이 있다
	// 5자리 숫자 중 정답이 있다.

	// 1~9을 넣어본다
	// 그때 섹션수가 줄지 않았다 -> x????는 다 만들 수 있다.
	// 섹션 수가 줄었다. -> 이 중에 정답이 있다.
	// 다시 0~9을 넣어본다.
	// 섹션 수가 줄지 않았다. -> xy???는 다 만들 수 있다.
	// 섹션 수가 줄었다. -> 이 중에 정답이 있다.
	// 섹션이 0이 되면 나머지 숫자 중 없는 숫자를 넣는다.

	cout << ans;
	

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :