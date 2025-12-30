#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    const int INF = 1e9;

    // dp[r][c][dir]
    // dir = 0(↙), 1(↓), 2(↘)
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(3, INF)));

    // 첫 줄은 그냥 넣기
    for (int i = 0; i < M; i++) {
        for (int dir = 0; dir < 3; dir++) {
            dp[0][i][dir] = grid[0][i];
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int dir = 0; dir < 3; dir++) {

                int prev = j;
                if (dir == 0) prev = j + 1;
                if (dir == 2) prev = j - 1;

                if (prev < 0 || prev >= M) continue;

                for (int prevDir = 0; prevDir < 3; prevDir++) {
                    if (prevDir == dir) continue;
                    dp[i][j][dir] = min(dp[i][j][dir], dp[i-1][prev][prevDir] + grid[i][j]);
                }
            }
        }
    }

    int answer = INF;
    for (int i = 0; i < M; i++) {
        for (int dir = 0; dir < 3; dir++) {
            answer = min(answer, dp[N-1][i][dir]);
        }
    }
    cout << answer << '\n';

    return 0;
}
