#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;
};

point home; 
point conv[101];
point festival;
vector<bool> visited;

bool bfs(int n) {
    queue<point> q;
    q.push(home);

    while (!q.empty()) {
        point cur = q.front();
        q.pop();

        // 갈 수 있는 곳 체크 
        if (abs(cur.x - festival.x) + abs(cur.y - festival.y) <= 1000) {
            return true;
        }

        // 편의점 탐색
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int dist = abs(cur.x - conv[i].x) + abs(cur.y - conv[i].y);
            if (dist <= 1000) {
                visited[i] = true;
                q.push(conv[i]);
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;

        cin >> home.x >> home.y;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> conv[i].x >> conv[i].y;
        }
        cin >> festival.x >> festival.y;

        visited.assign(n, false);
        if (bfs(n)) cout << "happy\n";
        else cout << "sad\n";
    }

    return 0;
}
