#include <string>
#include <vector>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();

    vector<vector<int>> danger = board;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                for (int d = 0; d < 8; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    danger[nx][ny] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (danger[i][j] == 0) answer++;
        }
    }

    return answer;
}
