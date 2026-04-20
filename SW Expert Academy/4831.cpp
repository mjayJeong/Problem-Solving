#include <iostream>
#include <vector>

using namespace std;

int find_close_stop(vector<int>& stop, int start, int end) {
  int answer = start;
  for (int i = 0; i < stop.size(); i++) {
    if (stop[i] <= start) continue;
    if (stop[i] > end) break;
    answer = stop[i];
  }
  
  return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int tc = 1;

  while (T--) {
    int K, N, M;
    cin >> K >> N >> M;
    vector<int> stop(M);

    for (int i = 0; i < M; i++) {
      cin >> stop[i];
    }

    int now = 0;
    int answer = 0; 
    bool possible = true;

    while (now + K < N) {
      int next = find_close_stop(stop, now, now + K);
      
      // 도달할 수 없는 경우
      if (next == now) {
        possible = false;
        break;
      }

      now = next;
      answer++;
    }

    if (!possible) answer = 0; 

    cout << '#' << tc << ' ' << answer << '\n';
    tc++;
  }

  return 0;
}
