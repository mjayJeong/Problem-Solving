#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 작은 숫자가 먼저 나오게

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curTime = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curTime > dist[curNode]) continue;  // 이미 더 빠른 경로 있으면 스킵

        for (auto next : graph[curNode]) {
            int nextNode = next.first;
            int cost = next.second;

            if (dist[nextNode] > curTime + cost) {
                dist[nextNode] = curTime + cost;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    return dist;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n, d, c;
        cin >> n >> d >> c;

        vector<vector<pair<int, int>>> graph(n + 1);

        for (int j = 0; j < d; j++) {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({a, s});     // b -> a로 연결
        }

        vector<int> dist = dijkstra(c, graph, n);

        int infected = 0;
        int lastTime = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] != INF) {
                infected++;
                lastTime = max(lastTime, dist[i]);
            }
        }
        cout << infected << " " << lastTime << '\n';
    }
    
    return 0;
}
