#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    unordered_set<string> seen;
    int answer = 0;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (s == "ENTER") {
            seen.clear();
        } else {
            if (seen.insert(s).second) { // 새로 들어갔으면 true
                answer++;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
