#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> flies(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> flies[i][j];
      }
    }

    int answer = 0; 

    for (int i = 0; i <= N - M; i++) {
      for (int j = 0; j <= N - M; j++) {
        int sum = 0;

        for (int x = i; x < i + M; x++) {
          for (int y = j; y < j + M; y++) {
            sum += flies[x][y];
          }
        }

        answer = max(answer, sum);
      }
    }
    cout << '#' << t << ' ' << answer << '\n';
  }
  
  return 0;
}
