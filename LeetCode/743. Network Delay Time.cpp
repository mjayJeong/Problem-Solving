#include <iostream>
#include <queue>
#include <algorithm>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        // 인접 리스트로 변환 
        for (auto& t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        // 거리, 정점으로 삽입
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        const int INF = 1e9;
        vector<int> dist(n + 1, INF);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();

            if (d > dist[cur]) continue;

            for (auto& [nxt, w] : graph[cur]) {
                if (d + w < dist[nxt]) {
                    dist[nxt] = d + w;
                    pq.push({dist[nxt], nxt});
                }
            }
        }

        int answer = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;
            answer = max(answer, dist[i]);
        }
        return answer;
    }
};
