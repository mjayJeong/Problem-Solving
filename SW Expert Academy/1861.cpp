#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N;
vector<vector<int>> room;
vector<vector<bool>> visited;

int bfs(int start_x, int start_y) 
{
  int cnt = 1; 
  queue<pair<int, int>> q;
  q.push({start_x, start_y});
  visited[start_x][start_y] = true;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      if (!visited[nx][ny] && room[nx][ny] == room[x][y] + 1) {
        visited[nx][ny] = true;
        q.push({nx, ny});
        cnt++;
      }
    }
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int idx = 1;

  while (T--) {
    cin >> N;
    room.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> room[i][j];
      }
    }

    int answer = 0;
    int room_num = 0;
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        visited.assign(N, vector<bool>(N, false));
        int tmp = bfs(i, j);
          
        if (tmp > answer) {
          answer = tmp;
          room_num = room[i][j];
        } else if (tmp == answer) {
          if (room_num > room[i][j]) {
            room_num = room[i][j];
          }
        }
      }
    }

    cout << '#' << idx << ' ' << room_num << ' ' << answer << '\n';
    idx++;
  }

  return 0;
}
