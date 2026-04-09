#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W;
  cin >> H >> W;
  vector<string> area(H);

  for (int i = 0; i < H; i++) {
    cin >> area[i];
  }

  vector<vector<int>> answer(H, vector<int>(W));

  for (int i = 0; i < H; i++) {
    int idx = -1;
    for (int j = 0; j < W; j++) {
      if (area[i][j] == 'c') {
        idx = 0;
        answer[i][j] = idx;
      } else {
        if (idx == -1) {    // 옆에 구름이 없는 경우
          answer[i][j] = -1;
        } else {
          idx++;
          answer[i][j] = idx;
        }
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << answer[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
