#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<vector<int>> adj(N+1);       // 연결 상태 저장
    vector<int> time(N+1);              // 걸리는 시간 저장
    vector<int> degree(N+1, 0);       
    // dp 테이블 (i번 작업이 끝나는 시간)
    vector<int> dp(N+1, 0);              

    for (int i = 1; i <= N; i++) {
        int p;
        cin >> time[i] >> p;
        for (int j = 0; j < p; j++) {
            int node; 
            cin >> node;
            adj[node].push_back(i);
            degree[i]++;
        }
    }

    queue<int> q;
    // degree 0인거 queue에 넣기 
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            q.push(i);
            dp[i] = time[i];     // 선행 작업 없으면 자기 시간만에 끝
        } 
    }

    // queue 빌 때까지 degree 감소 시키면서 
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int nxt : adj[cur]) {
            // cur 끝난 뒤에 nxt 진행 가능
            dp[nxt] = max(dp[nxt], dp[cur] + time[nxt]);

            degree[nxt]--;
            if (degree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    int answer = 0; 
    for (int i = 1; i <= N; i++) {
        answer = max(answer, dp[i]);
    }
    cout << answer << "\n";
    
    return 0;
}
