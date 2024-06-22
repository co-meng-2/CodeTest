

#include <algorithm>
#include <vector>
using namespace std;

int solution(int n, std::vector<int> weak, std::vector<int> dist) {

    int wcnt = weak.size();
    for (int i = 0; i < wcnt; ++i)
        weak.push_back(n + weak[i]);
    sort(dist.begin(), dist.end());

    int mn = 1e9;
	do
	{
        for (int widx = 0; widx < wcnt; ++widx)
        {
            int cnt = 0;
            int didx = 0;
            int swidx = widx;
            while(didx < dist.size())
            {
                int pos = weak[swidx] + dist[didx];
                for (int i = swidx; i < weak.size(); ++i)
                {
                    if ( weak[swidx] <= weak[i] && weak[i] <= pos )
                        cnt++;
                    else
                    {
                        swidx = i;
                        break;
                    }
                }

                if(cnt >= wcnt)
                {
                    mn = min(mn, didx + 1);
                    break;
                }
                didx++;
            }
        }

	} while (next_permutation(dist.begin(), dist.end()));

    return mn == 1e9 ? -1 : mn;
}
