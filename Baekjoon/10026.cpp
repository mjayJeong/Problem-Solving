#include <iostream>
#include <string>

using namespace std;

int N;
char map[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool normal_visited[101][101];
bool disabled_visited[101][101];

// 정상 사람 구하기 
void normal_dfs(int x, int y, char c) {
    normal_visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !normal_visited[nx][ny] && map[nx][ny] == c) {
            normal_dfs(nx, ny, c);
        }
    }
    return;
}

// 적록색약 구하기
void disabled_dfs(int x, int y, char c) {
    disabled_visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !disabled_visited[nx][ny] && map[nx][ny] == c) {
            disabled_dfs(nx, ny, c);
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < line.size(); j++) {
            map[i][j] = line[j];
        }
    }

    int normal = 0;
    int disabled = 0;

    // 정상 사람 구하기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!normal_visited[i][j]) {
                normal++;
                normal_dfs(i, j, map[i][j]);
            }
        }
    }

    // 지도 수정
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
        }
    }

    // 적록색약 구하기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!disabled_visited[i][j]) {
                disabled++;
                disabled_dfs(i, j, map[i][j]);
            }
        }
    }

    cout << normal << ' ' << disabled << '\n';

    return 0;
}
