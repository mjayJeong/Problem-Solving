#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> pick;
vector<bool> visited, finished;
int teamCnt;    // 팀에 속한 학생 수

void dfs(int cur) {
    visited[cur] = true;
    int nxt = pick[cur];

    if (!visited[nxt]) {
        dfs(nxt);
    } else if (!finished[nxt]) {        // 사이클 발견 조건
        // nxt부터 다시 돌아오면서 사이클 크기 세기
        int x = nxt;
        while (x != cur) {
            teamCnt++;
            x = pick[x];
        }
        teamCnt++;  // cur까지 포함
    }
    finished[cur] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        pick.assign(n+1, 0);
        visited.assign(n+1, false);
        finished.assign(n+1, false);

        for (int i = 1; i <= n; i++) {
            cin >> pick[i];
        }

        teamCnt = 0;

        // 모든 노드에서 DFS 돌리기
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i);
        }

        // 팀에 속하지 못한 사람
        cout << n - teamCnt << '\n';
    }
    return 0;
}
