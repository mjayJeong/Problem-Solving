#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W;
  cin >> H >> W;
  vector<int> block(W);

  for (int i = 0; i < W; i++) {
    cin >> block[i];
  }

  vector<int> leftMax, rightMax;
  leftMax.assign(W, 0);
  rightMax.assign(W, 0);

  // 각 구역의 왼쪽 최대 구하기 
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < i; j++) {
      leftMax[i] = max(leftMax[i], block[j]);
    }
  }

  // 오른쪽 최대 구하기 
  for (int i = 0; i < W; i++) {
    for (int j = i; j < W; j++) {
      rightMax[i] = max(rightMax[i], block[j]);
    }
  }

  int answer = 0; 

  for (int i = 0; i < W; i++) {
    answer += max(0, min(leftMax[i], rightMax[i]) - block[i]);
  }

  cout << answer << '\n';

  return 0;
}
