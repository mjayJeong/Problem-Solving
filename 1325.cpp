#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N+1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[B].push_back(A); 
    }

    vector<int> visited(N+1, 0);
    int stamp = 0;      // visited 초기화 대신  

    int best = 0;
    vector<int> answer;
    
    for (int start = 1; start <= N; start++) {
        stamp++;
        queue<int> q;
        q.push(start);
        visited[start] = stamp;

        int cnt = 0; 
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            cnt++;

            for (int nxt : graph[cur]) {
                if (visited[nxt] == stamp) continue;
                visited[nxt] = stamp;
                q.push(nxt);
            }
        }

        if (cnt > best) {
            best = cnt;
            answer.clear(); // 더 높은 값이 있으면 초기화
            answer.push_back(start);
        } else if (cnt == best) {
            answer.push_back(start);
        }
    }

    sort(answer.begin(), answer.end());
    for (int x : answer) cout << x << ' ';
    cout << "\n";

    return 0;
}
