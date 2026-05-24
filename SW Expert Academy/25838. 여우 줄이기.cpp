#include <iostream>
#include <string>

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

    string word;
    cin >> word;
    string st;

    for (int i = 0; i < word.size(); i++) {
      st.push_back(word[i]);

      int len = st.size();

      if (len >= 3 &&
        st[len-3] == 'f' &&
        st[len-2] == 'o' &&
        st[len-1] == 'x') {
        st.pop_back();
        st.pop_back();
        st.pop_back();
      }
    }

    cout << st.size() << '\n';
  }

  return 0;
}
