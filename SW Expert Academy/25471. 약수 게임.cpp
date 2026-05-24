#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        if (N % 2 == 1) {
            cout << "B\n";
            continue;
        }

        long long temp = N;
        int cnt = 0;

        while (temp % 2 == 0) {
            temp /= 2;
            cnt++;
        }

        if (temp == 1 && cnt % 2 == 1) {
            cout << "B\n";
        } else {
            cout << "A\n";
        }
    }

    return 0;
}
