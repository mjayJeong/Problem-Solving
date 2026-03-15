#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) 
{
  if (a.second != b.second) return a.second > b.second;
  if (a.first.size() != b.first.size()) return a.first.size() > b.first.size(); 
  return a.first < b.first;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  unordered_map<string, int> um;
  vector<pair<string, int>> arr;

  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;

    if (word.size() >= M) {
      um[word]++;
    }
  }

  // 배열에 삽입
  for (auto& k : um) {
    arr.push_back(k);
  }

  sort(arr.begin(), arr.end(), cmp);

  for (auto& p : arr) {
    cout << p.first << '\n';
  }

  return 0; 
}
