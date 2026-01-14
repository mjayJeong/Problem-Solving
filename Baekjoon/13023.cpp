#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> g;
vector<bool> visited;
bool found = false;

void dfs(int cur, int depth) {
    if (found) return;
    if (depth == 4) { // A-B-C-D-E : 간선 4개
        found = true;
        return;
    }

    for (int nxt : g[cur]) {
        if (!visited[nxt]) {
            visited[nxt] = true;
            dfs(nxt, depth + 1);
            visited[nxt] = false; // backtracking
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    g.assign(N, {});
    visited.assign(N, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
        if (found) break;
    }

    cout << (found ? 1 : 0) << "\n";
    return 0;
}
