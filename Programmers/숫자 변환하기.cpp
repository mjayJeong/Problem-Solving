#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    vector<int> dist(y + 1, -1);
    queue<int> q;
    
    q.push(x);
    dist[x] = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == y) return dist[cur];
        
        int next1 = cur + n;
        int next2 = cur * 2;
        int next3 = cur * 3;
        
        if (next1 <= y && dist[next1] == -1) {
            dist[next1] = dist[cur] + 1;
            q.push(next1);
        }
        if (next2 <= y && dist[next2] == -1) {
            dist[next2] = dist[cur] + 1;
            q.push(next2);
        }
        if (next3 <= y && dist[next3] == -1) {
            dist[next3] = dist[cur] + 1;
            q.push(next3);
        }
    }
    
    return -1;
}
