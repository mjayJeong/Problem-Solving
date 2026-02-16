#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, L;
    cin >> N >> K;
    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = 1;
    }

    cin >> L;
    vector<pair<int, char>> direction(L);
    for (int i = 0; i < L; i++) {
        cin >> direction[i].first >> direction[i].second;
    }

    // 방향 : 0 (오른쪽), 1 (아래), 2(왼쪽), 3(위)
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int dir = 0;

    deque<pair<int, int>> snake;        // 뱀 위치 저장 
    snake.push_front({0, 0});           // 시작 (0, 0)

    vector<vector<bool>> body(N, vector<bool>(N, false));       // 자기 몸 충돌 체크
    body[0][0] = true;

    int time = 0;
    int tIdx = 0;

    while (true) {  
        time++;

        // 1. 다음 머리 위치
        int headR = snake.front().first;
        int headC = snake.front().second;
        int nr = headR + dr[dir];
        int nc = headC + dc[dir];

        // 2. 벽 충돌 체크
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
            cout << time << "\n";
            return 0;
        }

        // 3. 자기 몸 충돌 체크
        if (body[nr][nc]) {
            cout << time << '\n';
            return 0;
        }

        // 4. 머리 이동 
        snake.push_front({nr, nc});
        body[nr][nc] = true;

        // 5. 사과 여부 체크
        if (board[nr][nc] == 1) {
            board[nr][nc] = 0;
        } else { 
            // 사과 없으면 꼬리 줄이기 
            auto tail = snake.back();
            snake.pop_back();
            body[tail.first][tail.second] = false;
        }

        // 6. 방향 전환
        if (tIdx < L && direction[tIdx].first == time) {
            char c = direction[tIdx].second;
            if (c == 'L') dir = (dir + 3) % 4;  // 왼쪽 회전
            else dir = (dir + 1) % 4;
            tIdx++;
        }
    }

    return 0;
}
