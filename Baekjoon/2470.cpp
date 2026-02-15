#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int left = 0, right = N - 1;
    long long cnt = LLONG_MAX;
    long long ans1 = arr[left], ans2 = arr[right];
    

    while (left < right) {
        long long sum = arr[left] + arr[right];
        long long ab = llabs(sum);

        if (ab < cnt) {
            cnt = ab;
            ans1 = arr[left];
            ans2 = arr[right];
        }

        if (sum == 0) break;
        else if (sum < 0) left++;
        else right--;
    }
    if (ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << ' ' << ans2 << '\n';

    return 0;
}
