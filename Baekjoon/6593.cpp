#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int bfs(int L, int R, int C, const vector<vector<vector<char>>>& building, int sz, int sx, int sy) {
    vector<vector<vector<int>>> dist(L, vector<vector<int>>(R, vector<int>(C, -1)));
    queue<tuple<int, int, int>> q;

    dist[sz][sx][sy] = 0;
    q.push({sz, sx, sy});

    while (!q.empty()) {
        auto [z, x, y] = q.front();
        q.pop();

        if (building[z][x][y] == 'E') {
            return dist[z][x][y];
        }

        for (int dir = 0; dir < 6; dir++) {
            int nz = z + dx[dir];
            int nx = x + dy[dir];
            int ny = y + dz[dir];

            if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (building[nz][nx][ny] == '#') continue;
            if (dist[nz][nx][ny] != -1) continue;

            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int L, R, C;
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0) break;

        vector<vector<vector<char>>> building(L, vector<vector<char>>(R, vector<char>(C)));

        tuple<int, int, int> start;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                string line;
                cin >> line;

                for (int k = 0; k < line.size(); k++) {
                    building[i][j][k] = line[k];

                    if (building[i][j][k] == 'S') {
                        start = {i, j, k};
                    }
                }
            }
        }

        int answer = bfs(L, R, C, building, get<0>(start), get<1>(start), get<2>(start));
        
        if (answer == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << answer << " minute(s).\n";
    }

    return 0;
}
