#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};   // 북, 동, 남, 서 순서
int dy[] = {0, 1, 0, -1};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int r, c, d;
    cin >> r >> c >> d;

    vector<vector<int>> room(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    int answer = 0;

    while (true) {
        // 1. 현재 칸 청소
        if (room[r][c] == 0) {
            room[r][c] = 2;
            answer++;
        }

        // 2. 주변 4칸 확인
        bool found = false;
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;    // 반시계 회전 
            int nx = r + dx[d];
            int ny = c + dy[d];

            // 청소되지 않은 칸 발견 시 이동
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && room[nx][ny] == 0) {
                r = nx;
                c = ny;
                found = true;
                break;
            }
        }
        if (found) continue;

        // 3. 네 칸 모두 청소된 경우 -> 후진
        int back_dir = (d + 2) % 4;
        int bx = r + dx[back_dir];
        int by = c + dy[back_dir];

        if (bx >= 0 && bx < N && by >= 0 && by < M && room[bx][by] != 1) {
            r = bx;
            c = by;
        } else {
            break;
        }
    }
    cout << answer << '\n';

    return 0;
}
