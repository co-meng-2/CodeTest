#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <string>
using std::string;

// ���ڿ� ST���־��� S�� T�� �ٲٴ� ����
// ���ڿ��� A�� B�θ� ����
// 1. ���ڿ��� �ڿ� A�� �߰�
// 2. ���ڿ��� ������ �ڿ� B�� �߰�
// S�� T�� �ٲ� �� ������ 1�ƴϸ� 0�� ���
// S 1 - 999 T 2 - 1000
// T�� ���̰� S�� ���̺��� ũ��.

// Ǯ�� ���
// Brute -> 2^(T-S) �Ұ���
// ��ġ�� ���ڿ��� ���� ������ ����
// BFS�� �ɷ��ش�? or backtracking?

// backtracking A�� B�� ���� 2^500
// BFS ���� ���

void Sub(string& str)
{
	str.pop_back();
}

void SubReverse(string& str)
{
	str.pop_back();
	string tmp;
	for(auto it = str.rbegin(); it != str.rend(); ++it)
		tmp.push_back(*it);
	str = tmp;
}

int main()
{
	string S, T;
	cin >> S;
	cin >> T;

	while(T.size() > S.size())
	{
		if (T.back() == 'A')
			Sub(T);
		else if (T.back() == 'B')
			SubReverse(T);
	}

	bool ret = true;
	for(int i = 0; i < S.size(); ++i)
	{
		if(T[i] != S[i])
		{
			ret = false;
			break;
		}
	}

	cout << ret;

	return 0;
}

// 30��