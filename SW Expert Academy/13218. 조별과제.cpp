#include <iostream>

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

    int answer = N / 3;

    cout << '#' << t << ' ' << answer << '\n';
  }

  return 0;
}
