#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;

    vector<vector<char>> board(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
      string line;
      cin >> line;
      for (int j = 0; j < N; j++) {
        board[i][j] = line[j];
      }
    }

    int minRow = N, maxRow = -1, minCol = N, maxCol = -1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] == '#') {
          minRow = min(minRow, i);
          maxRow = max(maxRow, i);
          minCol = min(minCol, j);
          maxCol = max(maxCol, j);
        }
      }
    }

    bool flag = true;

    int height = maxRow - minRow + 1;
    int width = maxCol - minCol + 1;

    if (height != width) {
      flag = false;
    }

    for (int i = minRow; i <= maxRow; i++) {
      if (!flag) break;
      for (int j = minCol; j <= maxCol; j++) {
        if (board[i][j] != '#') {
          flag = false;
          break;
        }
      }
    }

    if (flag) cout << '#' << t << ' ' << "yes" << '\n';  
    else cout << '#' << t << ' ' << "no" << '\n';  

  }

  return 0;
}
