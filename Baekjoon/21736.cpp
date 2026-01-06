#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<vector<char>> campus;
vector<vector<bool>> visited;
int answer = 0; 

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int start_x, int start_y) {
    visited[start_x][start_y] = true;
    queue<pair<int, int>> q;
    q.push({start_x, start_y});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && campus[nx][ny] != 'X') {
                visited[nx][ny] = true;

                if (campus[nx][ny] == 'P') answer++;
                
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    campus.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));

    pair<int, int> doyeon;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;

        for (int j = 0; j < word.size(); j++) {
            campus[i][j] = word[j];
            if (campus[i][j] == 'I') {
                doyeon = {i, j};
            }
        }
    }
    
    bfs(doyeon.first, doyeon.second);

    if (answer) cout << answer << '\n';
    else cout << "TT" << '\n';

    return 0;
}
