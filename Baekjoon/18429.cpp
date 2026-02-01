#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> kit;
vector<bool> visited;
int answer = 0;

void backtracking(int start, int depth, int now_weight)
{
    if (depth == N) {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        int next_weight = now_weight + kit[i] - K;  // 무게 갱신
        if (next_weight < 500) continue;

        visited[i] = true;
        backtracking(i, depth + 1, next_weight);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    kit.resize(N);
    visited.assign(N, false);

    for (int i = 0; i < N; i++) {
        cin >> kit[i];
    }

    // N개 키트에 대해서 모두 backtracking 돌려서 경우의 수 
    backtracking(0, 0, 500); 

    cout << answer << "\n";

    return 0;
}
