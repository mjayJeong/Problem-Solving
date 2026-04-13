#include <iostream>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    string s = to_string(i);
    int cnt = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '3' || s[j] == '6' || s[j] == '9') {
        cnt++;
      }
    } 

    string answer;
    if (cnt == 0) cout << s << ' ';
    else {
      for (int j = 0; j < cnt; j++) {
        answer += '-';
      }
      cout << answer << ' ';
    }
  }

  return 0;
}
