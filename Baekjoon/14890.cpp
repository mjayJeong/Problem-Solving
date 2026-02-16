#include <iostream>
#include <vector>

using namespace std;

int N, L;

bool canPass(const vector<int>& a) {
    vector<bool> used(N, false);

    for (int i = 0; i < N - 1; i++) {
        if (a[i] == a[i + 1]) continue;

        // 올라가는 경우: a[i] -> a[i+1] = a[i] + 1
        if (a[i + 1] == a[i] + 1) {
            for (int k = 0; k < L; k++) {
                int idx = i - k;
                if (idx < 0) return false;
                if (used[idx]) return false;
                if (a[idx] != a[i]) return false;
            }
            for (int k = 0; k < L; k++) used[i - k] = true;
        }
        // 내려가는 경우: a[i] -> a[i+1] = a[i] - 1
        else if (a[i + 1] == a[i] - 1) {
            for (int k = 1; k <= L; k++) {
                int idx = i + k;
                if (idx >= N) return false;
                if (used[idx]) return false;
                if (a[idx] != a[i + 1]) return false;
            }
            for (int k = 1; k <= L; k++) used[i + k] = true;
        }
        // 높이 차이가 2 이상이면 불가
        else {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;
    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int ans = 0;

    // 행 검사
    for (int i = 0; i < N; i++) {
        vector<int> line(N);
        for (int j = 0; j < N; j++) line[j] = board[i][j];
        if (canPass(line)) ans++;
    }

    // 열 검사
    for (int j = 0; j < N; j++) {
        vector<int> line(N);
        for (int i = 0; i < N; i++) line[i] = board[i][j];
        if (canPass(line)) ans++;
    }

    cout << ans << "\n";
    return 0;
}
