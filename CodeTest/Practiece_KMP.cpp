#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 실패함수 F(x) = S[0:x+1]에서 자기 자신을 제외하고 접두사와 접미사가 일치하는 최대 길이
// 예시 F(5)는 S중 6글자 중에 5글자, 4글자, 3...2...1 이렇게 접두사와 접미사를 비교하여 최대 길이를 찾는다.
// F(k)는 최대 F(k-1) + 1이다.
// 그렇다면 F(k-1) = x라고 한다면, 마지막으로 일치하는 문자의 인덱스는 x - 1이다.
// 다시 그렇다면 F(k)는 S[F(k-1)]과 S[k]를 비교하면 된다.

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
