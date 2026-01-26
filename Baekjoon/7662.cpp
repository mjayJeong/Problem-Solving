#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        multiset<long long> ms;
        for (int i = 0; i < k; i++) {
            char c;
            long long n;
            cin >> c >> n;

            if (c == 'I') {
                ms.insert(n);
            } else if (c == 'D') {
                if (ms.empty()) continue;
                if (n == -1) {
                    ms.erase(ms.begin());
                } else if (n == 1) {
                    ms.erase(--ms.end());
                }
            }
        }
        if (!ms.empty()) {
            cout << *(--ms.end()) << " " << *ms.begin() << "\n";
        } else {
            cout << "EMPTY" << "\n";
        }
    }

    return 0;
}
