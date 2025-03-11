#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
vector<pair<int, int>> a[1001];
int d[1001];

void dijkstra(int start) {
    fill(d, d + 1001, INF);
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (d[current] < distance) continue;

        for (auto &edge : a[current]) {
            int next = edge.first;
            int nextDistance = distance + edge.second;

            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(nextDistance, next));
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start);

    cout << d[end] << endl;

    return 0;
}
