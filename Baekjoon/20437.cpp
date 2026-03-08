#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        string W;
        int K;
        cin >> W >> K;

        vector<int> pos[26];

        for (int i = 0; i < W.size(); i++) {
            pos[W[i] - 'a'].push_back(i);
        }

        int shortest = INT_MAX;
        int longest = -1;

        for (int c = 0; c < 26; c++) {
            if (pos[c].size() < K) continue;

            for (int i = 0; i + K - 1 < pos[c].size(); i++) {
                int len = pos[c][i + K - 1] - pos[c][i] + 1;
                shortest = min(shortest, len);
                longest = max(longest, len);
            }
        }

        if (longest == -1) {
            cout << -1 << '\n';
        } else {
            cout << shortest << ' ' << longest << '\n';
        }
    }

    return 0;
}
