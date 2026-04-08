#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<char>> map;
vector<vector<bool>> visited;

bool bfs(int start_x, int start_y) {
  queue<pair<int, int>> q;
  
  q.push({start_x, start_y});
  visited[start_x][start_y] = true;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (x == 13 && y == 13) return true;

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16) continue;
      if (!visited[nx][ny] && map[nx][ny] != '1') {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 10;

  while (T--) {
    int t;
    cin >> t;
    
    map.resize(16, vector<char>(16));

    for (int i = 0; i < 16; i++) {
      string line;
      cin >> line;
      for (int j = 0; j < line.size(); j++) {
        map[i][j] = line[j];
      }
    }

    visited.assign(16, vector<bool>(16, false));

    bool flag = bfs(1, 1);

    if (flag) cout << '#' << t << ' ' << 1 << '\n';
    else cout << '#' << t << ' ' << 0 << '\n';
  }

  return 0;
}
