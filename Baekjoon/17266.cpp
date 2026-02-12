#include <iostream>
#include <vector>
using namespace std;

int N, M;

bool check(int H, vector<int>& ramp) {
    if (ramp[0] - H > 0) return false;

    for (int i = 1; i < M; i++) {
        if (ramp[i] - ramp[i-1] > 2 * H) return false;
    }

    if (ramp[M-1] + H < N) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<int> ramp(M);

    for (int i = 0; i < M; i++) cin >> ramp[i];

    int low = 0, high = N;
    int answer = N;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (check(mid, ramp)) {
            answer = mid;
            high = mid - 1;  // 최소 높이 찾기
        } else {
            low = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}
