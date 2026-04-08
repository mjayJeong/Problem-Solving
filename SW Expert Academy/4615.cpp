#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void check(vector<vector<char>>& board, int x, int y, int N) 
{
    char myColor = board[x][y];
    char enemy = (myColor == 'B') ? 'W' : 'B';

    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        vector<pair<int, int>> toFlip;

        while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (board[nx][ny] == enemy) {
                toFlip.push_back({nx, ny});
            }
            else if (board[nx][ny] == myColor) {
                if (!toFlip.empty()) {
                    for (auto& p : toFlip) {
                        board[p.first][p.second] = myColor;
                    }
                }
                break;
            }
            else {
                break;
            }

            nx += dx[d];
            ny += dy[d];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    int tc = 1;

    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<char>> board(N, vector<char>(N, '.'));

        // 초기 세팅
        board[N/2 - 1][N/2 - 1] = 'W';
        board[N/2 - 1][N/2] = 'B';
        board[N/2][N/2 - 1] = 'B';
        board[N/2][N/2] = 'W';

        for (int i = 0; i < M; i++) {
            int y, x, c;
            cin >> y >> x >> c;

            x--;
            y--;

            if (c == 1) {
                board[x][y] = 'B';
            } else {
                board[x][y] = 'W';
            }

            check(board, x, y, N);
        }

        int black = 0, white = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'B') black++;
                else if (board[i][j] == 'W') white++;
            }
        }

        cout << "#" << tc << " " << black << " " << white << "\n";
        tc++;
    }

    return 0;
}
