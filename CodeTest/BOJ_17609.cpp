#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

// ȸ�� 0
// �ϳ� ����� ȸ�� -> ���� ȸ�� 1
// ������ 2
// ���ڿ��� ���� T ( 1 - 30 ) / ���ڿ� ���� L ( 3 - 100,000 )

// ���� ȸ���� �Ǻ� -> �� �ڿ��� �� �ڸ��� �پ�Ѿ 

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