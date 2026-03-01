#include <iostream>
#include <vector>

using namespace std;

// x를 숫자 버튼으로 입력 가능하면 자릿수 반환, 불가능하면 -1 반환
int canPress(int x, const vector<bool>& broken) {
  if (x == 0) {
    return broken[0] ? -1 : 1;
  }

  int cnt = 0;
  while (x > 0) {
    int d = x % 10;
    if (broken[d]) return -1;
    cnt++;
    x /= 10;
  }

  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<bool> broken(10, false);
  for (int i = 0; i < M; i++) {
    int b; 
    cin >> b;
    broken[b] = true;
  }

  // 1. +/- 만으로 가는 경우
  int answer = abs(N - 100);

  // 2. 숫자 입력 후 +/- 사용
  for (int x = 0; x <= 1000000; x++) {
    int len = canPress(x, broken);
    if (len == -1) continue;
    answer = min(answer, len + abs(N-x));
  }

  cout << answer << '\n';

  return 0;
}
