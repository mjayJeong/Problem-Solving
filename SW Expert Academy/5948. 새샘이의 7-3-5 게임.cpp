#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<int, greater<int>> s;
vector<bool> visited;

void backtracking(vector<int>& v, int start, int depth, int sum) 
{
  if (depth == 3) {
    s.insert(sum);
    return;
  }

  for (int i = start; i < v.size(); i++) {
    if (!visited[i]) {
      visited[i] = true;
      backtracking(v, i + 1, depth + 1, sum + v[i]);
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

  for (int t = 1; t <= T; t++) {
    vector<int> v(7);
    for (int i = 0; i < 7; i++) {
      cin >> v[i];
    }
    
    s.clear();
    visited.assign(7, false);
    backtracking(v, 0, 0, 0);
    
    auto it = next(s.begin(), 4);
    cout << '#' << t << ' ' << *it << '\n';
  }

  return 0;
}
