#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double answer;
int N;
vector<vector<int>> prob;
vector<bool> visited;

void backtracking(int depth, double now_prob) 
{
  if (depth == N) {
    answer = max(answer, now_prob);
    return;
  }

  if (now_prob <= answer) return;

  for (int j = 0; j < N; j++) {
    if (!visited[j]) {
      visited[j] = true;
      backtracking(depth + 1, now_prob * (prob[depth][j] / 100.0));
      visited[j] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cin >> N;
    answer = 0;

    prob.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> prob[i][j];
      }
    } 

    visited.assign(N, false);
    // 완전 탐색으로 모든 경우의 수
    backtracking(0, 1.0);

    cout << "#" << t << " ";
    cout << fixed << setprecision(6) << answer * 100 << '\n';   // 소수점 고정 출력
  }

  return 0;
}
