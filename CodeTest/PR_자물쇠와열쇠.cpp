#include <string>
#include <vector>

using namespace std;
using pii = pair<int, int>;

// 중심으로부터 (x, -y)로 움직이면 시계방향 회전
vector<pii> Rotate(vector<vector<int>>& board)
{
    vector<vector<int>> rotated(board.size(), vector<int>(board.size(), 0));
    vector<pii> keys;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j)
        {
            rotated[i][j] = board[board.size() - 1 - j][i];
            if (rotated[i][j])
                keys.push_back({i,j});
        }
    }
    board = rotated;
    return keys;
}

bool OOB(int y, int x, int mx)
{
    return y < 0 || y >= mx || x < 0 || x >= mx;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int keySize = key.size();
    int lockSize = lock.size();
    int holeCnt = 0;
    pii root{};
    for (int i = 0; i < lockSize; ++i)
        for (int j = 0; j < lockSize; ++j)
            if (lock[i][j] == 0)
            {
                holeCnt++;
                root = { i, j };
            }

    for (int k = 0; k < 4; ++k)
    {
        vector<pii> keys = Rotate(key);
        if (keys.empty())
        {
            if (holeCnt == 0)
                return true;
            return false;
        }
        pii pivot; // y + pivot = i
        for (auto [y, x] : keys)
        {
            pivot.first = root.first - y;
            pivot.second = root.second - x;
            auto lockcpy = lock;
            int cnt = 0;
            for (auto [cy, cx] : keys)
            {
                int ny = cy + pivot.first;
                int nx = cx + pivot.second;

                if (OOB(ny, nx, lockSize)) continue;
                if (lockcpy[ny][nx]) break;

                lockcpy[ny][nx] = 1;
                cnt++;
            }
            if (cnt == holeCnt)
                return true;
        }
    }
    // 4 * ( 1600 + 400 * 400) = 660000
    return answer;
}

int main()
{
    solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1} }, { {1, 1, 1},{1, 1, 0},{1, 0, 1}});
}