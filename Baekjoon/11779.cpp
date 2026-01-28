#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
    }
    int start, arrive;
    cin >> start >> arrive;

    vector<int> parent(n+1, -1);
    long long INF = 1e9;
    vector<long long> dist(n+1, INF);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        if (d != dist[cur]) continue;

        for (auto [nxt, w] : graph[cur]) {
            if (d + w < dist[nxt]) {
                parent[nxt] = cur;
                dist[nxt] = d + w;
                pq.push({d+w, nxt});
            }
        }
    }

    vector<int> path;
    int cur = arrive;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    cout << dist[arrive] << "\n";
    cout << path.size() << "\n";
    for (int city : path) cout << city << " ";
    cout << "\n";

    return 0;
}
