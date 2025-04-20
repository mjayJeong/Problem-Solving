#include <iostream>
#include <queue>
#include <vector>

using namespace std;


bool visited[101];
vector<int> graph[101];
int dist[101];

void bfs(int start, int n) 
{
    queue<int> q;
    q.push(start);

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }

    visited[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
                dist[y] = dist[x] + 1;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int minBacon = 10000000;
    int result;

    for (int i = 1; i <= n; i++) {
        bfs(i, n);
        int baconNum = 0;
        for (int j = 1; j <= n; j++) {
            baconNum += dist[j];
        }

        if (baconNum < minBacon) {
            minBacon = baconNum;
            result = i;
        }
    }

    cout << result << endl;

    return 0;
}
