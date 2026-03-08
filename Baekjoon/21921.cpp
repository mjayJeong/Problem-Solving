#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, X;
  cin >> N >> X;
  vector<int> visit(N);
  for (int i = 0; i < N; i++) {
    cin >> visit[i];
  }

  int sum = 0;
  for (int i = 0; i < X; i++) {
    sum += visit[i];
  }

  int answer = sum;
  int cnt = 1;

  for (int i = X; i < N; i++) {
    sum += visit[i];
    sum -= visit[i - X];

    if (sum > answer) {
      answer = sum;
      cnt = 1;
    } else if (sum == answer) {
      cnt++;
    }
  }

  if (answer == 0) {
    cout << "SAD\n";
  } else {
    cout << answer << '\n' << cnt << '\n';
  }

  return 0;
}
