#include <iostream>
#include <vector>

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

    vector<int> score(N);
    int total = 0;
    for (int i = 0; i < N; i++ ) {
      cin >> score[i];
      total += score[i];
    }

    vector<bool> possible(total + 1, false);  // 각 숫자 만드는 거 가능한지 체크
    possible[0] = true;

    for (int i = 0; i < N; i++) {
      for (int sum = total; sum >= 0; sum--) {
        if (possible[sum] && sum + score[i] <= total) {
          possible[sum + score[i]] = true;
        }
      } 
    }

    int answer = 0; 
    for (int i = 0; i <= total; i++) {
      if (possible[i]) answer++;
    }
    
    cout << '#' << tc << ' ' << answer << '\n';
    tc++;
  }

  return 0;
}
