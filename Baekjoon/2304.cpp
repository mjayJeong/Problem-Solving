#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  vector<pair<int, int>> pil(N);
  pair<int, int> max_t = {0, 0};         // 최대 높이와 위치 저장 
  int maxH = 0;

  for (int i = 0; i < N; i++) {
    cin >> pil[i].first >> pil[i].second;
    maxH = max(maxH, pil[i].second);
  }

  sort(pil.begin(), pil.end());

  // 최고 높이 기준 왼쪽, 오른쪽 인덱스 구하기
  int leftMaxIdx = -1, rightMaxIdx = -1;
  for (int i = 0; i < N; i++) {
    if (pil[i].second == maxH) {
      if (leftMaxIdx == -1) leftMaxIdx = i;
      rightMaxIdx = i;
    }
  }

  int answer = 0; 

  // 왼쪽 영역 구하기
  int leftH = pil[0].second;
  int leftX = pil[0].first;

  for (int i = 1; i <= leftMaxIdx; i++) {
    if (pil[i].second >= leftH) {
      answer += leftH * (pil[i].first - leftX);
      leftH = pil[i].second;
      leftX = pil[i].first;
    }
  }

  // 오른쪽 영역 구하기
  int rightH = pil[N-1].second;
  int rightX = pil[N-1].first;

  for (int i = N - 2; i >= rightMaxIdx; i--) {
    if (pil[i].second >= rightH) {
      answer += rightH * (rightX - pil[i].first);
      rightH = pil[i].second;
      rightX = pil[i].first;
    }
  }

  // 최고 높이 구간 면적
  answer += (pil[rightMaxIdx].first - pil[leftMaxIdx].first + 1) * maxH;

  cout << answer << '\n';

  return 0;
}
