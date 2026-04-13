#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int answer;
int limit;
vector<unordered_set<string>> visited;

void dfs(string& s, int cnt) {
  if (visited[cnt].count(s)) return;
  visited[cnt].insert(s);

  if (cnt == limit) {
    answer = max(answer, stoi(s));
    return;
  }

  int len = s.size();

  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      swap(s[i], s[j]);
      dfs(s, cnt + 1);
      swap(s[i], s[j]);
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
    string s;
    cin >> s >> limit;

    answer = 0;
    visited.assign(limit + 1, unordered_set<string>());

    dfs(s, 0);
    
    cout << '#' << tc << " " << answer << '\n';
    tc++;
  }

  return 0;
}
