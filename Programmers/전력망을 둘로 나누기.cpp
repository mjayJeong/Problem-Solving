#include <string>
#include <vector>
#include <queue>

using namespace std;

// 끊은 것 고려해서 한쪽만 count하는 bfs
int bfs(int start, int n, vector<vector<int>>& tree, int cutA, int cutB) 
{  
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : tree[cur]) {
            if ((cur == cutA && next == cutB) || (cur == cutB && next == cutA)) continue;
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 10000;
    
    vector<vector<int>> tree(101);
    
    // graph 만들기
    for (vector<int> wire : wires) {
        tree[wire[0]].push_back(wire[1]);
        tree[wire[1]].push_back(wire[0]);
    }
    
    for (auto& w : wires) {
        int a = w[0], b = w[1];
        int cnt = bfs(a, n, tree, a, b);
        int diff = abs(cnt - (n - cnt));
        answer = min(answer, diff);
    }
    
    return answer;
}

// 완전 탐색으로 하나씩 끊어보기
// BFS, DFS로 개수 세기 
// 최소값 갱신하면서 전체 경우에 대해서 탐색 
