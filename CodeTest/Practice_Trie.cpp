#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// �ִ� 10000 ������ �빮�� ���ڿ� 500��

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
		// �ڽ� ������ ���ٸ�
		if (nxt[cur][c2i(c)] == -1)
			nxt[cur][c2i(c)] = unused++; // �ڽ� ��ȣ�� �Ҵ��ϰ� �����, ���� �Ҵ��� ���� ����
		cur = nxt[cur][c2i(c)];

		// ��ȭ��ȣ��
		// if(chk[cur]) return �� �߰�
	}
	
	// �ܾ� ���� üũ
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