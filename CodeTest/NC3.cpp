#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <algorithm>

int board[3][3]{};
// ���� ���ڿ����� string ABC�ε� ���� -'A'�� 0, 1, 2�� �ٲ㼭 ����ϴ�.
int w1[3]{}, w2[3]{}; // 3��¥�� ���ڿ�
int wr1[3], wr2[3]{}; // 3��¥�� ���ڿ� �Ųٷ� 
bool r1 = false; // 1�� ���ڿ� �Ųٷ� ����� ������
bool r2 = false; // 2�� ���ڿ� �Ųٷ� ����� ������

// ��, ��, �밢�� üũ
int check(int w[3])
{
	int cnt = 0;
	bool b;
	b = true;
	for(int i = 0; i < 3; ++i)
	{
		if (board[i][i] != w[i])
			b = false;
	}
	if (b)
		cnt++;

	b = true;
	for (int i = 0; i < 3; ++i)
	{
		if (board[i][2-i] != w[i])
			b = false;
	}
	if (b)
		cnt++;

	for(int i = 0; i < 3; ++i)
	{
		b = true;
		for(int j =0; j < 3; ++j)
		{
			if (board[i][j] != w[j])
				b = false;
		}
		if (b)
			cnt++;
	}

	for (int j = 0; j < 3; ++j)
	{
		b = true;
		for (int i = 0; i < 3; ++i)
		{
			if (board[i][j] != w[i])
				b = false;
		}
		if (b)
			cnt++;
	}

	return cnt;
}

int ans = 0;
void dfs(int depth)
{
	if(depth == 9)
	{
		int c1 = check(w1);
		if(!r1)
		{
			c1 += check(wr1);
		}

		int c2 = check(w2);
		if(!r2)
		{
			c2 += check(wr2);
		}
		if (c1 == 1 && c2 == 1)
			ans++;
		
		return;
	}

	int save = board[depth / 3][depth % 3];
	for(int i = 0; i < 3; ++i)
	{
		board[depth / 3][depth % 3] = i;
		dfs(depth + 1);
	}
	board[depth / 3][depth % 3] = save;
}

int main()
{
	// ���ڿ�, ���ڿ� �Ųٷ�
	for(int i = 0; i < 3; ++i)
	{
		cin >> w1[i];
		wr1[2 - i] = w1[i];
	}

	for (int i = 0; i < 3; ++i)
	{
		cin >> w2[i];
		wr2[2 - i] = w2[i];
	}

	// �յڰ� ������ üũ
	r1 = w1[0] == w1[2];
	r2 = w2[0] == w2[2];

	dfs(0);

	cout << ans;

	return 0;
}