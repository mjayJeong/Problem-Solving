#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int K, N;
vector<long long> line;

bool cut(long long l) {
    long long cnt = 0;
    for (int i = 0; i < K; i++) {
        cnt += line[i] / l;
    }
    return cnt >= N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> N;
    line.resize(K);
    for (int i = 0; i < K; i++) cin >> line[i];
    sort(line.begin(), line.end());

    long long answer = 0;
    long long left = 1, right = line[K - 1];

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (cut(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
