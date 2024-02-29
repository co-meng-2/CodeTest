#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 최대 10000 길이의 대문자 문자열 500개

const int root = 1;
int unused = 2;

int c2i(char c)
{
	return c - 'A';
}

void insert(const string input, vector<vector<int>>& nxt, vector<bool>& chk)
{
	int cur = root;
	
	for (auto c : input)
	{
		// 자식 정보가 없다면
		if (nxt[cur][c2i(c)] == -1)
			nxt[cur][c2i(c)] = unused++; // 자식 번호를 할당하고 기억후, 다음 할당을 위해 증가
		cur = nxt[cur][c2i(c)];

		// 전화번호부
		// if(chk[cur]) return 값 추가
	}
	
	// 단어 끝점 체크
	chk[cur] = true;
}

bool find(const string input, vector<vector<int>>& nxt, vector<bool>& chk)
{
	int cur = root;
	
	for (auto c : input)
	{
		if (nxt[cur][c2i(c)] == -1)
			return false;
		cur = nxt[cur][c2i(c)];
	}

	return chk[cur];
}

bool erase(const string input, vector<vector<int>>& nxt, vector<bool>& chk)
{
	int cur = root;

	for (auto c : input)
	{
		if (nxt[cur][c2i(c)] == -1)
			return false;
		cur = nxt[cur][c2i(c)];
	}

	if (chk[cur])
		return chk[cur] = false;
}

int main()
{
	const int Max = 10000 * 500 + 1;
	vector<bool> chk(Max);
	vector<vector<int>> nxt(Max, vector<int>(26, -1));

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		insert(s, nxt, chk);
	}

	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;

		cout << find(s, nxt, chk) <<"\n";
	}

	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;

		erase(s, nxt, chk);
		cout << find(s, nxt, chk) << "\n";
	}
}