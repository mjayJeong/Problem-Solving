#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> note;
int R, C;
vector<vector<int>> sticker;

// 스티커 붙이는 함수
bool attach(int x, int y) {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            // 못 붙이면 false 반환
            if (note[x+i][y+j] == 1 && sticker[i][j] == 1) return false;

    // 붙일 수 있으면 붙이고 (1로 바꾸고) return true
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (sticker[i][j] == 1) note[x+i][y+j] = 1;

    return true;
}

// 스티커 회전 시키는 함수
void rotateSticker() {
    vector<vector<int>> tmp(C, vector<int>(R));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            // 직접 배열 그려서 계산한 공식
            tmp[j][R - 1 - i] = sticker[i][j];
    sticker = tmp;
    swap(R, C);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    note.assign(N, vector<int>(M, 0));

    while (K--) {
        cin >> R >> C;
        sticker.assign(R, vector<int>(C, 0));
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> sticker[i][j];

        // 노트의 왼쪽 상단부터 오른쪽 하단까지 탐색 
        // 회전 4번
        for (int rot = 0; rot < 4; rot++) {
            bool pasted = false;    // 붙였는지 확인

            for (int x = 0; x <= N - R && !pasted; x++) {
                for (int y = 0; y <= M - C; y++) {
                    if (attach(x, y)) { pasted = true; break; }
                }
            }

            if (pasted) break;      // 이미 붙였으면 회전 X
            rotateSticker();
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            answer += note[i][j];

    cout << answer << "\n";
    return 0;
}
