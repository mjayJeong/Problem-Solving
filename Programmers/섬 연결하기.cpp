#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> graph; 
int answer;

void prim(int start, int n)
{
    vector<bool> visited(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    visited[start] = true;
    for (auto [to, w] : graph[start]) {
        pq.push({w, to});
    }
    
    int cnt = 1;        // 방문한 섬 개수 
    answer = 0; 
    
    while (!pq.empty() && cnt < n) {
        auto [w, v] = pq.top();
        pq.pop();
        
        if (visited[v]) continue;
        
        visited[v] = true;
        answer += w;
        cnt++;
        
        for (auto [to, nw] : graph[v]) {
            if (!visited[to]) pq.push({nw, to});
        }
    }
    
}

int solution(int n, vector<vector<int>> costs) {    
    graph.clear();
    graph.resize(n);
    
    for (int i = 0; i < costs.size(); i++) {
        graph[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        graph[costs[i][1]].push_back({costs[i][0], costs[i][2]});
    }
    
    prim(0, n);
    
    return answer;
}
