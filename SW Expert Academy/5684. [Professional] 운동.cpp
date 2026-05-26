#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;
const int INF = 1e9;

int dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> dist(N + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > dist[cur]) continue;

        for (auto [next, weight] : graph[cur]) {
            int nextCost = cost + weight;

            if (next == start && nextCost > 0) {
                return nextCost;
            }

            if (dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    return INF;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        vector<vector<pair<int, int>>> graph(N + 1);

        for (int i = 0; i < M; i++) {
            int s, e, c;
            cin >> s >> e >> c;
            graph[s].push_back({e, c});
        }

        int answer = INF;

        for (int i = 1; i <= N; i++) {
            answer = min(answer, dijkstra(graph, i));
        }

        cout << "#" << t << " ";
        if (answer == INF) cout << -1 << '\n';
        else cout << answer << '\n';
    }

    return 0;
}
