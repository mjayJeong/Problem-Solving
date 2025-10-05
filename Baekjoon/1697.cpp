#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> dist(100001, -1);
    queue<int> q;

    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == k) {
            cout << dist[x] << '\n';
            return 0;
        }

        for (int nx : {x - 1, x + 1, x * 2}) {
            if (nx >= 0 && nx <= 100000 && dist[nx] == -1) {
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }
    }

    return 0;
}
