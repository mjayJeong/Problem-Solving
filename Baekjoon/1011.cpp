#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        long long x, y;
        cin >> x >> y;

        long long d = y - x;
        long long k = floor(sqrt(d));

        long long answer = 0;

        if (d == k * k) {
            answer = 2 * k - 1;
        } else if (d > k*k && d <= k*k + k) {
            answer = 2 * k;
        } else if (d > k*k + k && d < (k+1)*(k+1)) {
            answer = 2 * k + 1;
        }
        cout << answer << '\n';
    }

    return 0;
}
