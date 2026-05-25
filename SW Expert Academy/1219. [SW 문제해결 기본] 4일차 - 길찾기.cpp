#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

void bfs(vector<vector<int>>& graph, int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto g : graph[cur]) {
      if (!visited[g]) {
        visited[g] = true;
        q.push(g);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int t = 1; t <= 10; t++) {
    int tc, N;
    cin >> tc >> N;
    vector<vector<int>> graph(100);

    for (int i = 0; i < N; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
    }

    visited.assign(101, false);
    bfs(graph, 0);
    
    if (visited[99]) cout << '#' << t << ' ' << 1 << '\n';
    else cout << '#' << t << ' ' << 0 << '\n';
  }

  return 0; 
}
