#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<pair<int, int>> lecture(N);
  for (int i = 0; i < N; i++) {
    cin >> lecture[i].first >> lecture[i].second;
  }

  sort(lecture.begin(), lecture.end());

  priority_queue<int, vector<int>, greater<int>> pq;

  for (auto [s, t] : lecture) {
    if (!pq.empty() && pq.top() <= s) pq.pop();
    pq.push(t); 
  }

  cout << pq.size() << '\n';

  return 0;
}
