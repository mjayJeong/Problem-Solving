#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

// 다익스트라 거리 구하기 
vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& graph, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    pq.push({0, start});
    
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
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // 인접 리스트로 변환
    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < fares.size(); i++) {
        graph[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        graph[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    
    vector<int> distS = dijkstra(n, graph, s);
    vector<int> distA = dijkstra(n, graph, a);
    vector<int> distB = dijkstra(n, graph, b);
    
    long long answer = 1e18;
    
    // 모든 지점에 대해서 경우의 수 구하기 
    for (int i = 1; i <= n; i++) {
        long long total_cost = distS[i] + distA[i] + distB[i];
        answer = min(answer, total_cost);
    }
    
    return answer;
}
