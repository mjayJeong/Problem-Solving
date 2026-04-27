#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<vector<char>> board;
set<string> s;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void backtracking(int x, int y, string cur) 
{
  if (cur.size() == 7) {
    s.insert(cur);
    return;   
  }

  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
    backtracking(nx, ny, cur + board[nx][ny]);
  }
}

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    board.assign(4, vector<char>(4));
    s.clear();

    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        cin >> board[j][k];
      }
    }

    // 모든 지점에서 백트래킹 돌리기 
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        string init;
        backtracking(j, k, init);
      }
    }

    cout << '#' << i << ' ' << s.size() << '\n';
  }


  return 0;
}
