#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int answer = 0; 

// 최대값 탐색
int get_maxVal(const vector<vector<int>>& b) {
  int mx = 0; 
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      mx = max(mx, b[i][j]);
    }
  }
  return mx;
}

// 한 줄을 왼쪽으로 밀어서 합치기 
vector<int> mergeLeftLine(const vector<int>& line) {
  vector<int> nonzero;
  for (int x : line) {
    if (x != 0) nonzero.push_back(x);   // 0 아닌 값 삽입
  }

  vector<int> out;
  for (int i = 0; i < nonzero.size(); i++) {
    if (i + 1 < nonzero.size() && nonzero[i] == nonzero[i+1]) {
      out.push_back(nonzero[i] * 2);
      i++;    // 합쳤으니깐 하나는 건너뜀
    } else {
      out.push_back(nonzero[i]);
    }
  }

  while (out.size() < N) out.push_back(0);    // 나머지는 0으로 채우기
  return out; 
}

// dir = 0 (위) / dir = 1 (아래) / dir = 2 (왼쪽) / dir = 3 (오른쪽)
vector<vector<int>> moveBoard(const vector<vector<int>>& b, int dir) {
  vector<vector<int>> res(N, vector<int>(N, 0));

  if (dir == 2) {
    for (int i = 0; i < N; i++) {
      vector<int> line(N);
      for (int j = 0; j < N; j++) line[j] = b[i][j];

      vector<int> out = mergeLeftLine(line);
      for (int j = 0; j < N; j++) res[i][j] = out[j];
    }
  } else if (dir == 3) {    // Right (뒤집어서 Left로 처리)
        for (int i = 0; i < N; i++) {
            vector<int> line(N);
            for (int j = 0; j < N; j++) line[j] = b[i][N - 1 - j];

            vector<int> out = mergeLeftLine(line);
            for (int j = 0; j < N; j++) res[i][N - 1 - j] = out[j];
        }
    } else if (dir == 0) {    // Up (열을 뽑아서 Left로 처리)
        for (int j = 0; j < N; j++) {
            vector<int> line(N);
            for (int i = 0; i < N; i++) line[i] = b[i][j];

            vector<int> out = mergeLeftLine(line);
            for (int i = 0; i < N; i++) res[i][j] = out[i];
        }
    } else {    // Down (열을 뒤집어서 Left로 처리)
        for (int j = 0; j < N; j++) {
            vector<int> line(N);
            for (int i = 0; i < N; i++) line[i] = b[N - 1 - i][j];

            vector<int> out = mergeLeftLine(line);
            for (int i = 0; i < N; i++) res[N - 1 - i][j] = out[i];
        }
    }

    return res;
}

// 백트래킹으로 모든 경우의 수 탐색
void dfs(int depth, const vector<vector<int>>& b) {
  answer = max(answer, get_maxVal(b));
  if (depth == 5) return;

  for (int dir = 0; dir < 4; dir++) {
    vector<vector<int>> nb = moveBoard(b, dir);
    if (nb == b) continue;  // 변화 없으면 중단
    dfs(depth + 1, nb);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  vector<vector<int>> board(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  dfs(0, board);
  cout << answer << '\n';

  return 0;
}
