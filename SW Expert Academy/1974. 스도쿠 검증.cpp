#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudoku;

// 가로 줄 체크
bool check_width() {
  for (int i = 0; i < 9; i++) {
    vector<int> cnt(10, 0);
    for (int j = 0; j < 9; j++) {
      cnt[sudoku[i][j]]++;
    }

    for (int j = 1; j <= 9; j++) {
      if (cnt[j] != 1) return false;
    }
  }
  return true;
}

// 세로 줄 체크
bool check_height() {
  for (int i = 0; i < 9; i++) {
    vector<int> cnt(10, 0);
    for (int j = 0; j < 9; j++) {
      cnt[sudoku[j][i]]++;
    }

    for (int j = 1; j <= 9; j++) {
      if (cnt[j] != 1) return false;
    }
  }
  return true;
}

// 3x3 사각형 체크
bool check_square() {
  for (int i = 0; i <= 6; i += 3) {
    for (int j = 0; j <= 6; j += 3) {

      vector<int> cnt(10, 0);
      for (int x = i; x < i + 3; x++) {
        for (int y = j; y < j + 3; y++) {
          cnt[sudoku[x][y]]++;
        }
      }

      for (int k = 1; k <= 9; k++) {
        if (cnt[k] != 1) return false;
      }
    }
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    sudoku.assign(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cin >> sudoku[i][j];
      }
    }

    if (check_width() && check_height() && check_square()) {
      cout << '#' << t << ' ' << 1 << '\n';
    } else {
      cout << '#' << t << ' ' << 0 << '\n';
    }

  }
  
  return 0;
}
