#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;
vector<vector<char>> board;
vector<vector<bool>> visited;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 주변에 지뢰 개수 탐색 함수
int get_mine(int x, int y) {
  int cnt = 0; 
  for (int d = 0; d < 8; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
    if (board[nx][ny] == '*') cnt++;
  }

  return cnt;
}

void bfs(int start_x, int start_y) {
  queue<pair<int, int>> q;
  q.push({start_x, start_y});
  visited[start_x][start_y] = true;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int d = 0; d < 8; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      if (!visited[nx][ny] && board[nx][ny] == '.') {
        visited[nx][ny] = true;
        if (get_mine(nx, ny) == 0) {    // 0인 부분만 퍼트리기
          q.push({nx, ny});
        }
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int tc = 1;

  while (T--) {
    cin >> N;
    board.assign(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
      string line;
      cin >> line;
      for (int j = 0; j < N; j++) {
        board[i][j] = line[j];
      }
    }

    visited.assign(N, vector<bool>(N, false));
    int answer = 0; 

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] == '.') {
          if (get_mine(i, j) == 0 && !visited[i][j]) {
            bfs(i, j);
            answer++;
          }
        }
      }
    }
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] == '.' && !visited[i][j]) answer++;
      }
    }

    cout << '#' << tc << ' ' << answer << '\n';

    tc++;
  }
  
  return 0;
}
