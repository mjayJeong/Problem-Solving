#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    vector<int> visited(F + 1, 0);
    queue<pair<int, int>> q;    // 현재 층, 버튼 누른 횟수
    q.push({S, 0});
    visited[S] = 1;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == G) {
            cout << cnt << '\n';
            return 0;
        }

        // 위로 이동 
        if (cur + U <= F && !visited[cur + U]) {
            visited[cur + U] = 1;
            q.push({cur + U, cnt + 1});
        }

        // 아래로 이동
        if (cur - D >= 1 && !visited[cur - D]) {
            visited[cur - D] = 1;
            q.push({cur - D, cnt + 1});
        }
    }
    cout << "use the stairs" << '\n';

    return 0;
}
