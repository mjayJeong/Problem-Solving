#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, X;
vector<long long> dist;
vector<long long> rdist;

void dijkstra(vector<vector<pair<int, int>>>& g, int k, vector<long long>& dd) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dd[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        if (d != dd[cur]) continue;

        for (auto [nxt, w] : g[cur]) {
            if (d + w < dd[nxt]) {
                dd[nxt] = d + w;
                pq.push({d+w, nxt});    
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> X;
    vector<vector<pair<int, int>>> adj(N+1);    // X에서 나가는 그래프
    vector<vector<pair<int, int>>> radj(N+1);   // X로 들어오는 그래프 (뒤집음)

    const long long INF = 4e18;
    dist.assign(N+1, INF);
    rdist.assign(N+1, INF);

    for (int i = 0; i < M; i++) {
        int s, e, t;
        cin >> s >> e >> t;

        adj[s].push_back({e, t});    // 원래 방향: s -> e
        radj[e].push_back({s, t});   // 뒤집은 방향: e -> s
    }

    dijkstra(adj, X, dist);
    dijkstra(radj, X, rdist);

    long long answer = 0; 
    for (int i = 1; i <= N; i++) {
        answer = max(answer, dist[i] + rdist[i]);
    }

    cout << answer << "\n";

    return 0;
}
