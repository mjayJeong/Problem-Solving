#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> visited;
vector<int> answer;

void backtracking(int cur, int depth) {
    if (depth == M) {
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = cur; i <= N; i++) {
        answer.push_back(i);
        backtracking(i + 1, depth + 1);
        answer.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    backtracking(1, 0);

    return 0;
}
