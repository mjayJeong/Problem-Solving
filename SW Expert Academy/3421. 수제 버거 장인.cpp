#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<bool>> bad;
vector<int> tmp;
int answer;

bool canPick(int ingredient) {
    for (int picked : tmp) {
        if (bad[ingredient][picked]) return false;
    }
    return true;
}

void backtracking(int start) {
    answer++; // 현재 tmp 조합도 하나의 버거

    for (int i = start; i <= N; i++) {
        if (canPick(i)) {
            tmp.push_back(i);
            backtracking(i + 1);
            tmp.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        bad.assign(N + 1, vector<bool>(N + 1, false));
        tmp.clear();
        answer = 0;

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            bad[a][b] = true;
            bad[b][a] = true;
        }

        backtracking(1);

        cout << '#' << t << ' ' << answer << '\n';
    }

    return 0;
}
