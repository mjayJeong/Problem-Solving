#include <iostream>
#include <vector>

using namespace std;

vector<int> kyu, hin;
vector<bool> visited;
int win_cnt, lose_cnt;

int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

void backtracking(int depth, int k_score, int h_score) {
    // 이미 승패 확정
    if (k_score > 85) {
        win_cnt += fact[9 - depth];
        return;
    }
    if (h_score > 85) {
        lose_cnt += fact[9 - depth];
        return;
    }

    if (depth == 9) {
        if (k_score > h_score) win_cnt++;
        else lose_cnt++;
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (!visited[i]) {
            visited[i] = true;

            int sum = kyu[depth] + hin[i];
            if (kyu[depth] > hin[i]) {
                backtracking(depth + 1, k_score + sum, h_score);
            } else {
                backtracking(depth + 1, k_score, h_score + sum);
            }

            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        vector<int> used(19, 0);
        kyu.assign(9, 0);
        hin.clear();
        visited.assign(9, false);
        win_cnt = 0;
        lose_cnt = 0;

        for (int i = 0; i < 9; i++) {
            cin >> kyu[i];
            used[kyu[i]] = 1;
        }

        for (int i = 1; i <= 18; i++) {
            if (!used[i]) hin.push_back(i);
        }

        backtracking(0, 0, 0);

        cout << "#" << tc << " " << win_cnt << " " << lose_cnt << '\n';
    }

    return 0;
}
