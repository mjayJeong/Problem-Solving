#include <iostream>
#include <string>
#include <vector>

using namespace std;

int R, C;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<char>> board;
vector<bool> used;
int answer;

void dfs(int x, int y, int depth)
{
  answer = max(answer, depth);
  
  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx >= 0 && nx < R && ny >= 0 && ny < C && !used[board[nx][ny] - 'A']) {
      used[board[nx][ny] - 'A'] = true;
      dfs(nx, ny, depth + 1);
      used[board[nx][ny] - 'A'] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> R >> C;
  board.resize(R, vector<char>(C));
  for (int i = 0; i < R; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < line.size(); j++) {
      board[i][j] = line[j];
    }
  }

  used.assign(26, false);
  used[board[0][0] - 'A'] = true;

  answer = 1;
  dfs(0, 0, 1);

  cout << answer << '\n';

  return 0;
}
