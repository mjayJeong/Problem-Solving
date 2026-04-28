#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int start) {
  for (auto nxt : graph[start]) {
    if (!visited[nxt]) {
      visited[nxt] = true;
      dfs(nxt);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N, M;
    cin >> N >> M;

    graph.assign(N+1, vector<int>());
    for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    
    int answer = 0; 
    visited.assign(N+1, false);
    for (int i = 1; i <= N; i++) {
      if (!visited[i]) {
        visited[i] = true;
        dfs(i);
        answer++;
      }
    }

    cout << '#' << t << ' ' << answer << '\n';
  }

  return 0;
}
