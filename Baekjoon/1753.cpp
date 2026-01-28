#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int V, E, k;
    cin >> V >> E >> k;

    // 인접 리스트 : u -> (v, w)
    vector<vector<pair<int, int>>> graph(V+1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    long long INF = 1e9;
    vector<long long> dist(V+1, INF);

    // (거리, 정점) 으로 넣기 
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        if (d != dist[cur]) continue;

        for (auto [nxt, w] : graph[cur]) {
            if (d + w < dist[nxt]) {
                dist[nxt] = d + w;
                pq.push({d+w, nxt});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
