#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string words[10] = {
        "ZRO", "ONE", "TWO", "THR", "FOR",
        "FIV", "SIX", "SVN", "EGT", "NIN"
    };

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        string testCase;
        int N;
        cin >> testCase >> N;

        vector<int> cnt(10, 0);

        for (int i = 0; i < N; i++) {
            string word;
            cin >> word;

            for (int j = 0; j < 10; j++) {
                if (word == words[j]) {
                    cnt[j]++;
                    break;
                }
            }
        }

        cout << testCase << '\n';

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << words[i] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
