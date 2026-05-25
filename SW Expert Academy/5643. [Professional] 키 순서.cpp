#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 연결되어 있는 개수 세기 
int bfs(vector<vector<int>>& g, int N, int start) {
  vector<bool> visited(N+1, false);
  queue<int> q;
  q.push(start);
  visited[start] = true;

  int cnt = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto nxt : g[cur]) {
      if (!visited[nxt]) {
        visited[nxt] = true;
        q.push(nxt);
        cnt++;
      }
    }
  }
  return cnt;
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

    vector<vector<int>> graph(N+1);      // 정방향 그래프 
    vector<vector<int>> reverse(N+1);    // 방향 바꾼 그래프

    for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      reverse[b].push_back(a);
    }
    
    int answer = 0;

    // 각 노드마다 카운팅 
    for (int i = 1; i <= N; i++) {
      int tmp = 0;
      tmp += bfs(graph, N, i);
      tmp += bfs(reverse, N, i);

      if (tmp == N - 1) answer++;
    }

    cout << '#' << t << ' ' << answer << '\n';
  }

  return 0; 
}

// 자기보다 작은 사람 + 자기보다 큰 사람 = N - 1 
