#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;

    vector<string> arr(N);
    vector<string> tmp1, tmp2;

    int mid = (N + 1) / 2;

    for (int i = 0; i < N; i++) {
      cin >> arr[i];

      if (i < mid) tmp1.push_back(arr[i]);
      else tmp2.push_back(arr[i]);
    }

    vector<string> answer;

    for (int i = 0; i < tmp2.size(); i++) {
      answer.push_back(tmp1[i]);
      answer.push_back(tmp2[i]);
    }

    if (tmp1.size() > tmp2.size()) {
      answer.push_back(tmp1.back());
    }

    cout << '#' << t << ' ';
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
