#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

// 회문 0
// 하나 지우면 회문 -> 유사 회문 1
// 나머지 2
// 문자열의 갯수 T ( 1 - 30 ) / 문자열 길이 L ( 3 - 100,000 )

// 유사 회문의 판별 -> 앞 뒤에서 각 자리를 뛰어넘어봄 

int T;

int dfs(int depth, string& str, int s, int e)
{
	if (depth == 2)
		return depth;

	while(s <= e)
	{
		if(str[s] != str[e])
		{
			return std::min(dfs(depth + 1, str, s + 1, e), dfs(depth + 1, str, s, e-1));
		}
		s++;
		e--;
	}

	return depth;
}

int main()
{
	fastio;

	int T;
	cin >> T;
	while(T > 0)
	{
		string str;
		cin >> str;
		cout << dfs(0, str, 0, str.size() - 1) << "\n";
		T--;
	}

	return 0;
}