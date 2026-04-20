#include <iostream>
#include <vector>

using namespace std;

int N;
int answer;
vector<vector<bool>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(vector<vector<int>>& v, int x, int y) {
  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
    if (v[nx][ny] > 0 && !visited[nx][ny]) {
      visited[nx][ny] = true;
      dfs(v, nx, ny);
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
    answer = 0; 
    vector<vector<int>> cheeze(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> cheeze[i][j];
      }
    }

    for (int i = 0; i <= 100; i++) {
      int cnt = 0; 
      vector<vector<int>> cpy = cheeze;
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          cpy[j][k] -= i;
        }
      }
      
      visited.assign(N, vector<bool>(N, false));

      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          if (cpy[j][k] > 0 && !visited[j][k]) {
            visited[j][k] = true;
            dfs(cpy, j, k);
            cnt++;
          } 
        }
      }
      answer = max(answer, cnt);
    }

    cout << '#' << tc << ' ' << answer << '\n';
    tc++;
  }

  return 0;
}
