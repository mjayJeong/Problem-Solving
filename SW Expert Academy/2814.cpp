#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int N, M;
int answer = 0;

void dfs(int cur, int cnt) {
  answer = max(answer, cnt);

  for (auto nxt : graph[cur]) {
    if (!visited[nxt]) {
      visited[nxt] = true;
      dfs(nxt, cnt + 1);
      visited[nxt] = false;
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
    cin >> N >> M;
    
    answer = 0;
    graph.assign(N + 1, vector<int>());
    visited.assign(N + 1, false);

    for (int i = 0; i < M; i++) {
      int x, y;
      cin >> x >> y;

      graph[x].push_back(y);
      graph[y].push_back(x);
    }

    for (int i = 1; i <= N; i++) {
      visited[i] = true;
      dfs(i, 1);
      visited[i] = false;
    }

    cout << '#' << tc << ' ' << answer << '\n';
    tc++;
  }

  return 0;
}
