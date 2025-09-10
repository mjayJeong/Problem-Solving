#include <iostream>
#include <vector>

using namespace std;

void dfs(int start, vector<int>& next, vector<bool>& visited) {
    visited[start] = true;
    int nxt = next[start];
    if (!visited[nxt]) dfs(nxt, next, visited);
}

int main() 
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        int answer = 0; 
        cin >> n;
        vector<int> next(n+1);
        for (int j = 1; j <= n; j++) {
            int dir;
            cin >> dir;
            next[j] = dir;
        }
        vector<bool> visited(n+1, false);  // visited 배열도 초기화 해야함 + vector 선언

        for (int k = 1; k < n+1; k++) {
            if (!visited[k]) {
                dfs(k, next, visited);
                answer++;
            }
        }
        cout << answer << '\n';
    }  

    return 0;
}
