#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int V;
vector<pair<int, int>> graph[100001];
bool visited[100001] = {false, };
int selected;
int answer = 0;

void dfs(int start, int depth) {
    // 현재 거리가 저장된 거리보다 길면 갱신
    if (answer < depth) {
        selected = start;
        answer = depth;
    }

    for (int i = 0; i < graph[start].size(); i++) {
        int nxt = graph[start][i].first;
        int cost = graph[start][i].second;
        if (!visited[nxt]) {
            visited[nxt] = true;
            dfs(nxt, depth + cost);
            visited[nxt] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V;

    for (int i = 0; i < V; i++) {
        int s, e, c;
        cin >> s;
        while (true) {
            cin >> e;
            if (e == -1) break;
            cin >> c;
            graph[s].push_back({e, c});
        }
    }
    
    // 임의의 정점 1부터 시작
    visited[1] = true;
    dfs(1, 0);

    fill(visited, visited + 100001, false);    // 방문 초기화
    answer = 0;                                // 거리 초기화  
    visited[selected] = true;
    dfs(selected, 0);

    cout << answer << '\n';

    return 0;
}
