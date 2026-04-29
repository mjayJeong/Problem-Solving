#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int K;
    cin >> K;
    string word;
    cin >> word;
    int n = word.size();

    vector<string> arr;

    for (int i = 0; i < n; i++) {
      string tmp;
      for (int j = i; j < n; j++) {
        tmp += word[j];
      }
      arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    cout << '#' << t << ' ' << arr[K-1] << '\n';
  }

  return 0;
}
