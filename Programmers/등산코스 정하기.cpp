#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& graph, vector<int>& gates, vector<bool>& isSummit)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INF);
    
    // 멀티 소스 다익스트라 
    for (int i = 0; i < gates.size(); i++) {
        dist[gates[i]] = 0;
        pq.push({0, gates[i]});
    }
    
    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        
        if (d > dist[cur]) continue;
        if (isSummit[cur]) continue;        // 정상이면 통과 
        
        for (auto& [nxt, w] : graph[cur]) {
            int nd = max(d, w);     // 경로의 worst 업데이트
            
            if (nd < dist[nxt]) {    // 덜 힘든 경로 업데이트 
                dist[nxt] = nd;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    return dist;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < paths.size(); i++) {
        graph[paths[i][0]].push_back({paths[i][1], paths[i][2]});
        graph[paths[i][1]].push_back({paths[i][0], paths[i][2]});
    }
    
    vector<bool> isSummit(n + 1, false);
    for (int s : summits) isSummit[s] = true;
    
    vector<int> dist = dijkstra(n, graph, gates, isSummit);
    
    sort(summits.begin(), summits.end());
    
    int bestSummit = -1;
    int bestIntensity = INF;
    
    for (int s : summits) {
        if (dist[s] < bestIntensity) {
            bestIntensity = dist[s];
            bestSummit = s;
        }
    }
    return {bestSummit, bestIntensity};
}
