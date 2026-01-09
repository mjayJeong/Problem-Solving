#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int standard = (int)round((double)n * 0.15);

    int sum = 0;
    for (int i = standard; i < n - standard; i++) {
        sum += arr[i];
    }

    double avg = (double)sum / (n - standard * 2);
    int answer = (int)round(avg);

    cout << answer << '\n';

    return 0;
}
