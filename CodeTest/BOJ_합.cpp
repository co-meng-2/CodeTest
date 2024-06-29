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
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// 10 90 720 5040 30240 151200 672000 2016000 4032000

using pli = pair<long long, int>;

int n;
pli w[10]{};
bool frontList[10]{};

bool alphaVisited[10]{};
int alphaCnt = 0;

bool used[10]{};
ll ans = 0;

int main()
{
	fastio;
	cin >> n;
	for(int i = 0 ; i < n; ++i)
	{
		string str;
		cin >> str;

		if(!frontList[str.front() - 'A'])
		{
			frontList[str.front() - 'A'] = true;
		}
		
		for(int j = 0; j < str.size(); ++j)
		{
			w[str[j] - 'A'].first += pow(10LL, str.size() - 1 - j);
			w[str[j] - 'A'].second = str[j] - 'A';

			if(!alphaVisited[str[j] - 'A'])
			{
				alphaVisited[str[j] - 'A'] = true;
				alphaCnt++;
			}
		}
	}

	sort(w, w + 10);

	// w 인덱스
	for(int i = 0; i < 10; ++i)
	{
		// w 인덱스로 찾은 알파벳에 대응 되는 숫자
		for(int j = 10 - alphaCnt; j < 10; ++j)
		{
			if (w[i].first == 0 || used[j] || (j == 0 && frontList[w[i].second])) continue;
			used[j] = true;
			ans += w[i].first * j;
			break;
		}
	}

	cout << ans;


	return 0;
}


// S : 1 16
// U : 1 18
// T : 1 50
// C : 2 26
// Total : 1h 10m

// Comment
// 생각보다 예외가 많았던 문제...