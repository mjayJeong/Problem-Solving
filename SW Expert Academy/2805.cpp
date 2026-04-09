#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int tc = 1;

  while (T--) {
    int N;
    cin >> N;

    vector<vector<int>> farm(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
      string line;
      cin >> line;

      for (int j = 0; j < line.size(); j++) {
        farm[i][j] = line[j] - '0';
      }
    }

    int M = N / 2;
    int left = M, right = M;

    int answer = 0; 
    for (int i = 0; i < N; i++) {
      for (int j = left; j <= right; j++) {
        answer += farm[i][j];
      }
      if (i < M) {
        left--;
        right++;
      } else {
        left++;
        right--;
      }
    }
    cout << '#' << tc << ' ' << answer << '\n';
    tc++;
  }

  return 0;
}
