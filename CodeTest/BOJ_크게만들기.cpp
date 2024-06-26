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
#include <unordered_set>
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int main()
{
	fastio;

	int n, k;
	cin >> n >> k;

	// 먼저 들어온 인덱스부터 꺼내쓸거기 때문에 Queue형태로 0~9숫자가 어느 인덱스에 있는지 넣어준다. 
	vector<queue<int>> numIdxs(10);
	for(int i = 0; i < n; ++i)
	{
		char num;
		cin >> num;
		numIdxs[num - '0'].push(i);
	}

	// 숫자 선택가능 범위
	int s = 0;
	int remain = n - k;
	int d = n - 1 - (remain - 1);
	// d = s + k 와 같이 최대로 숫자를 없앴을 경우를 상정하고 범위를 잡을수도 있지만
	// 내부에서 어떤 인덱스가 ans로서 선택되면, 그 전의 인덱스들을 모두 순회하고 파괴해야만 k가 유효해진다.
	// 따라서 넣을 숫자가 몇개 남았는지로 접근하는 것이 좋은듯.
	
	string ans;
	while (remain--)
	{
		for (int sel = 9; sel >= 0; --sel)
		{
			// 선택하려는 점의 인덱스가 시작점의 인덱스와 같거나 클 때 까지 pop
			while (!numIdxs[sel].empty() && numIdxs[sel].front() < s)
			{
				numIdxs[sel].pop();
			}

			if (numIdxs[sel].empty()) continue;

			int nxtIdx = numIdxs[sel].front();

			// 선택 가능하다면 9 ~ 0(sel) greedy하게 선택
			if (nxtIdx <= d)
			{
				ans += (sel + '0');
				numIdxs[sel].pop();

				s = nxtIdx + 1;
				d = n - 1 - (remain - 1);
				break;
			}
		}
	}

	cout << ans;

	return 0;
}


// S : 5 53
// U : 5 53
// T : 5 58
// C : 6 23
// Total : 30min

// Comment
// 아이디어 자체는 금방 떠올렸지만 인덱스 관련해서 좀 헷갈렸다.
// 포함과 비포함은 항상 왜 이렇게 헷갈리는걸까...