#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0.0);

        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();

            if (d < dist[cur]) continue;

            for (auto& [nxt, w] : graph[cur]) {
                if (d * w > dist[nxt]) {
                    dist[nxt] = d * w;
                    pq.push({dist[nxt], nxt});
                }
            }
        }

        return dist[end_node];
    }
};
