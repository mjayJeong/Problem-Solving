#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> graph;
vector<vector<int>> reach;

void dfs(int u, vector<int>& vis) {
    for (int i = 0; i < N; i++) {
        if (graph[u][i] && !vis[i]) {
            vis[i] = 1;
            dfs(i, vis);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    graph.assign(N, vector<int>(N, 0));
    reach.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        vector<int> vis(N, 0);
        dfs(i, vis);
        reach[i] = vis;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << reach[i][j] << (j + 1 == N? '\n' : ' ');
        }
    }
    return 0;
}
