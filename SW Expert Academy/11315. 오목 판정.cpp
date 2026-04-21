#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
bool answer;
vector<vector<char>> board;

// 방향 : 0, 1, 2, 3, 4, 5, 6, 7 으로 순서대로 설정
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x, int y, int direction, int depth) {
  if (board[x][y] == '.') return;

  if (depth == 5) {
    answer = true;
    return;
  }

  // 한 방향으로 쭉 탐색
  int nx = x + dx[direction];
  int ny = y + dy[direction];
  if (nx < 0 || nx >= N || ny < 0 || ny >= N) return;
  if (board[nx][ny] == 'o') dfs(nx, ny, direction, depth + 1);

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
    board.resize(N, vector<char>(N));
    answer = false;

    vector<pair<int, int>> stones;

    for (int i = 0; i < N; i++) {
      string line;
      cin >> line;
      for (int j = 0; j < N; j++) {
        board[i][j] = line[j];
        if (board[i][j] == 'o') {
          stones.push_back({i, j});
        }
      }
    }

    for (int i = 0; i < stones.size(); i++) {
      for (int j = 0; j < 8; j++) {
        dfs(stones[i].first, stones[i].second, j, 1);
      }
    }

    if (answer) cout << '#' << tc << ' ' << "YES" << '\n';
    else cout << '#' << tc << ' ' << "NO" << '\n';
    tc++;
  }

  return 0;
}
