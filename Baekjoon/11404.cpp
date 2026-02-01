#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    const int INF = 1e9;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));

    // 자기 자신의 거리는 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // 입력 
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    // 3중 루프 돌리기 
    for (int k = 1; k <= n; k++) {      // 거쳐 가는 간선   
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }       

    // 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
