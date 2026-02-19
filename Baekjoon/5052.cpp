#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<string> num_list(n);
        for (int i = 0; i < n; i++) {
            cin >> num_list[i];
        }
        sort(num_list.begin(), num_list.end());

        bool flag = true;
        for (int i = 0; i < num_list.size() - 1; i++) {
            string cur = num_list[i];
            string next = num_list[i+1];
            flag = true;
            if (cur.length() > next.length()) continue;
            if (cur == next.substr(0, cur.length())) {
                flag = false;
                break;
            }
        }
        if (!flag) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
