#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> students(n);
    for (int i = 0; i < n; i++) cin >> students[i];

    int b, c;
    cin >> b >> c;

    long long answer = 0;  

    for (int j = 0; j < n; j++) {
        answer++;
        int remain = students[j] - b;

        if (remain > 0) {
            answer += (remain + c - 1) / c;
        }
    }

    cout << answer << '\n';
    return 0;
}
