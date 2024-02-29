#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �����Լ� F(x) = S[0:x+1]���� �ڱ� �ڽ��� �����ϰ� ���λ�� ���̻簡 ��ġ�ϴ� �ִ� ����
// ���� F(5)�� S�� 6���� �߿� 5����, 4����, 3...2...1 �̷��� ���λ�� ���̻縦 ���Ͽ� �ִ� ���̸� ã�´�.
// F(k)�� �ִ� F(k-1) + 1�̴�.
// �׷��ٸ� F(k-1) = x��� �Ѵٸ�, ���������� ��ġ�ϴ� ������ �ε����� x - 1�̴�.
// �ٽ� �׷��ٸ� F(k)�� S[F(k-1)]�� S[k]�� ���ϸ� �ȴ�.

vector<int> failure(string& s)
{
	vector<int> f(s.size(), 0);
	int j = 0;
	for (int i = 1; i < s.size(); i++)
	{
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}
	return f;
}

int main()
{
	string s, p;
	cin >> s >> p;
	if (s.length() < p.length()) swap(s, p);

	vector<int> f = failure(p);
	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (j > 0 && s[i] != p[j]) j = f[j - 1];
		if (s[i] == p[j]) j++;

		if (j == p.length())
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}
