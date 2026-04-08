#include <iostream>
#include <vector>

using namespace std;

int answer = 1e9;

// 부분 집합 탐색만 하면 됨
void backtracking(int idx, int sum, vector<int>& height, int B)
{
  if (sum >= B) {
    answer = min(answer, sum - B);
    return;
  }

  if (idx == height.size()) return;

  if (sum - B >= answer) return;    // 가지치기

  // 현재 점원 선택
  backtracking(idx + 1, sum + height[idx], height, B);

  // 현재 점원 선택 x
  backtracking(idx + 1, sum, height, B);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int tc = 1;

  while (T--) {
    int N, B;
    cin >> N >> B;
    vector<int> height(N);

    for (int i = 0; i < N; i++) {
      cin >> height[i];
    }

    answer = 1e9;   // 테스트케이스마다 초기화
    backtracking(0, 0, height, B);


    cout << '#' << tc << ' ' << answer << '\n';
    tc++;
  }

  return 0;
}
