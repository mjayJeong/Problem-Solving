#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int tc = 1; tc <= 10; tc++) {
    int t;
    cin >> t;

    vector<vector<int>> ladder(100, vector<int>(100));
    int x = 99, y = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cin >> ladder[i][j];
            if (ladder[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }

    while (x > 0) {
        if (y - 1 >= 0 && ladder[x][y - 1] == 1) {
            while (y - 1 >= 0 && ladder[x][y - 1] == 1) {
                y--;
            }
            x--;
        }
        else if (y + 1 < 100 && ladder[x][y + 1] == 1) {
            while (y + 1 < 100 && ladder[x][y + 1] == 1) {
                y++;
            }
            x--;
        }
        else {
            x--;
        }
    }

    cout << "#" << tc << " " << y << '\n';
  }

  return 0;
}
