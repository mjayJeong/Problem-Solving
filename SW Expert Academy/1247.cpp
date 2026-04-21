#include <iostream>
#include <vector>

using namespace std;

pair<int, int> home;
pair<int, int> company;
vector<pair<int, int>> customer;
vector<bool> visited;

int N;
int answer;

void dfs(int x, int y, int depth, int cur) {
  if (cur >= answer) return;    // 조기 종료

  if (depth == N) {
    cur += abs(x - company.first) + abs(y- company.second);
    answer = min(answer, cur);
    return;
  }

  for (int i = 0; i < customer.size(); i++) {
    if (!visited[i]) {
      visited[i] = true;
      int dist = abs(x - customer[i].first) + abs(y - customer[i].second);
      dfs(customer[i].first, customer[i].second, depth + 1, cur + dist);
      visited[i] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int tc = 1;

  while (T--) {
    cin >> N;
    answer = 1e9; 

    customer.resize(N);

    cin >> home.first >> home.second;
    cin >> company.first >> company.second;
    for (int i = 0; i < N; i++) {
      cin >> customer[i].first >> customer[i].second;
    }

    visited.assign(N, false);
    dfs(home.first, home.second, 0, 0);

    cout << '#' << tc << ' ' << answer << '\n';
    tc++;
  }

  return 0; 
}
