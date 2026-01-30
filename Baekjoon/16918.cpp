#include <iostream>
#include <vector>

using namespace std;

int R, C, N;
vector<vector<char>> grid;
vector<pair<int, int>> bomb;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<string> explode_state(const vector<string>& b) {
    vector<string> res(R, string(C, 'O'));      // 전체 폭탄 설치

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (b[i][j] == 'O') {
                res[i][j] = '.';
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                        res[nx][ny] = '.';
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> N;

    vector<string> b(R);
    for (int i = 0; i < R; i++) cin >> b[i];

    if (N == 1) {
        for (int i = 0; i < R; i++) cout << b[i] << "\n";
    } else if (N % 2 == 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << "O";
            }
            cout << '\n';
        }
    } else {
        auto b3 = explode_state(b);
        auto b5 = explode_state(b3);

        if (N % 4 == 3) b = b3;
        else b = b5;    // N % 4 == 1

        for (int i = 0; i < R; i++) cout << b[i] << "\n";
    }

    return 0;
}
