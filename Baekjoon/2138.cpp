#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N;

void toggle(string& s, int n)
{
  for (int i = max(0, n-1); i <= min(N-1, n+1); i++) {
    s[i] = (s[i] == '0' ? '1' : '0');
  }
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  string cur, goal;
  cin >> cur >> goal;

  string temp1 = cur;
  string temp2 = cur;

  int ans1 = 0, ans2 = 0;

  // 1번 누르지 않은 경우 
  for (int i = 1; i < N; i++) {
    if (temp1[i-1] != goal[i-1]) {
      toggle(temp1, i);
      ans1++;
    }
  }

  // 1번 누른 경우 
  toggle(temp2, 0);
  ans2++; 

  for (int i = 1; i < N; i++) {
    if (temp2[i-1] != goal[i-1]) {
      toggle(temp2, i);
      ans2++;
    }
  }

  int answer = INT_MAX;

  if (temp1 == goal && temp2 == goal) {
    answer = min(ans1, ans2);
  } else if (temp1 == goal && temp2 != goal) {
    answer = ans1;
  } else if (temp1 != goal && temp2 == goal) {
    answer = ans2;
  } else {
    answer = -1;
  }

  cout << answer << '\n';

  return 0;
}
