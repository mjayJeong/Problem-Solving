#include <iostream>
#include <string>

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
    string w1, w2;
    cin >> w1 >> w2;

    int answer = 0; 
    for (int i = 0; i < N; i++) { 
      if (w1[i] == w2[i]) answer++; 
    }

    cout << '#' << t << ' ' << answer << '\n';
  }

  return 0;
}
