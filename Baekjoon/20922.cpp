#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> cnt(100001, 0);

    int left = 0, answer = 0;
    for (int r = 0; r < N; r++) {
        cnt[arr[r]]++;

        while (cnt[arr[r]] > K) {
            cnt[arr[left]]--;
            left++;
        }
        answer = max(answer, r - left + 1);
    }

    cout << answer << "\n";
    return 0;
}
