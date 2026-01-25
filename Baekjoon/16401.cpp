#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
vector<long long> arr;
int answer; 

bool check(long long len) {
    long long cnt = 0;
    for (int i = 0; i < N; i++) cnt += arr[i] / len;
    return cnt >= M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long low = 1;
    long long high = *max_element(arr.begin(), arr.end());
    long long answer = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (check(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
