// 빡 구현 해보자 
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int R, C, T;
vector<vector<int>> room;
int up;     // 공기청정기 윗 부분 위치
int down;   // 공기청정기 밑 부분 위치

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 미세먼지 확산 -> 새로운 배열에 복사해야 함 (기존에 것들도 중첩으로 될 수 있어서 )
// 기존 지도 돌면서 미세먼지 있는 위치에 있는 것들 
void diffusion() {
    vector<vector<int>> tmp(R, vector<int>(C, 0));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // 공기 청정기 위치면 그대로 tmp = -1
            if (room[i][j] == -1) {
                tmp[i][j] = -1;
                continue;
            }

            if (room[i][j] > 0) {
                // 네 방향으로 확산 시킴 
                int cnt = 0;
                int spread = room[i][j] / 5;

                for (int d = 0; d < 4; d++) {
                    int nx = dx[d] + i; 
                    int ny = dy[d] + j;

                    if (nx >= 0 && nx < R && ny >= 0 && ny < C && room[nx][ny] != -1) {
                        tmp[nx][ny] += spread;
                        cnt++;
                    }
                }
                // 남은 양 누적
                tmp[i][j] += room[i][j] - (spread * cnt);
            }
        }
    }
    room = move(tmp);

    return;
}

// 공기청정기 작동 
void turn_air() {
    // 위쪽(반시계) : up 행 기준
    // 1) 왼쪽 세로 (위로)
    for (int i = up - 1; i > 0; i--) room[i][0] = room[i - 1][0];
    // 2) 위 가로 (왼쪽으로)
    for (int j = 0; j < C - 1; j++) room[0][j] = room[0][j + 1];
    // 3) 오른쪽 세로 (아래로)
    for (int i = 0; i < up; i++) room[i][C - 1] = room[i + 1][C - 1];
    // 4) 아래 가로 (오른쪽으로) - 청정기 바로 위 행(up)
    for (int j = C - 1; j > 1; j--) room[up][j] = room[up][j - 1];
    room[up][1] = 0; // 청정기에서 나온 바람은 깨끗(0)

    // 아래쪽(시계) : down 행 기준
    // 1) 왼쪽 세로 (아래로)
    for (int i = down + 1; i < R - 1; i++) room[i][0] = room[i + 1][0];
    // 2) 아래 가로 (왼쪽으로)
    for (int j = 0; j < C - 1; j++) room[R - 1][j] = room[R - 1][j + 1];
    // 3) 오른쪽 세로 (위로)
    for (int i = R - 1; i > down; i--) room[i][C - 1] = room[i - 1][C - 1];
    // 4) 위 가로 (오른쪽으로) - 청정기 바로 아래 행(down)
    for (int j = C - 1; j > 1; j--) room[down][j] = room[down][j - 1];
    room[down][1] = 0;

    // 청정기 위치는 다시 -1로 
    room[up][0] = -1;
    room[down][0] = -1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> R >> C >> T;
    room.resize(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> room[i][j];
            if (room[i][j] == -1) {
                up = i-1;
                down = i;
            }
        }
    }

    // T만큼 반복 
    while (T--) {
        diffusion();
        turn_air();
    }

    int answer = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (room[i][j] == -1) continue;
            answer += room[i][j];
        }
    }
    cout << answer << "\n";

    return 0; 
}
