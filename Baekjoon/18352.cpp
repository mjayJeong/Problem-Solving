#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;
vector<vector<int>> road;
vector<int> dist;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : road[cur]) {
            if (dist[next] == -1) { 
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K >> X;

    road.resize(N + 1);
    dist.resize(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        road[a].push_back(b);
    }

    bfs(X);

    vector<int> answer;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            answer.push_back(i);
        }
    }

    if (answer.empty()) {
        cout << -1 << '\n';
    } else {
        sort(answer.begin(), answer.end());
        for (int city : answer) {
            cout << city << '\n';
        }
    }

    return 0;
}
