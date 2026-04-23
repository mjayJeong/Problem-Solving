#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int answer;

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;

  answer = start;

  while (!q.empty()) {
    int sz = q.size();
    int levelMax = 0;
    
    for (int i = 0; i < sz; i++) {
      int cur = q.front();
      q.pop();

      levelMax = max(levelMax, cur);    // 각 레벨에서 최대값 갱신

      for (int next : graph[cur]) {
        if (!visited[next]) {
          visited[next] = true;
          q.push(next);
        }
      }
    }
    answer = levelMax;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int t = 1; t <= 10; t++) {
    int N, start;
    cin >> N >> start;
    answer = 0; 

    graph.assign(101, vector<int>());
    for (int i = 0; i < N / 2; i++) {
      int from, to;
      cin >> from >> to;

      graph[from].push_back(to);
    }
    visited.assign(101, false);
    bfs(start);

    cout << '#' << t << ' ' << answer << '\n';
  }

  return 0;
}
