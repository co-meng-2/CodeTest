#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;

    int n = cards.size();
    int sCnt = n / 3;
    // 총 n/2개의 쌍
    // 손에 쌍 중 하나를 들고 있으면 coin을 반드시 소모.

    // 다 들고 있다고 가정하고 빼야 되는 순간에 판단?
    set<int> curCards;
    int complete = 0;
    for (int i = 0; i < n / 3; ++i)
    {
        if (curCards.find(n + 1 - cards[i]) != curCards.end())
        {
            complete++;
            curCards.erase(n + 1 - cards[i]);
        }
        else
            curCards.insert(cards[i]);
    }

    set<int> tmpCards;
    int turn = 0;
    for (int cur = n / 3; cur < n; cur += 2)
    {
        turn++;

        tmpCards.insert(cards[cur]);
        tmpCards.insert(cards[cur + 1]);

        if (complete == 0)
        {
            bool bFind = false;
            if (coin >= 1)
            {
                for (auto it : curCards)
                {
                    if (tmpCards.find(n + 1 - it) != tmpCards.end())
                    {
                        complete++;
                        tmpCards.erase(n + 1 - it);
                        curCards.erase(it);
                        coin--;
                        bFind = true;
                        break;
                    }
                }
            }

            if (!bFind && coin >= 2)
            {
                for (auto it : tmpCards)
                {
                    if (tmpCards.find(n + 1 - it) != tmpCards.end())
                    {
                        complete++;
                        tmpCards.erase(n + 1 - it);
                        tmpCards.erase(it);
                        coin -= 2;
                        break;
                    }
                }
            }
        }

        if (complete == 0)
            break;
        else
            complete--;

        if (n - 2 == cur)
            turn++;
    }

    answer = turn;

    return answer;
}