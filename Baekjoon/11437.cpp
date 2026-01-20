#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

void bfs(int node) {
    queue<int> q; 
    q.push(node);
    visited[node] = true;
    int level = 1; 
    int now_size = 1;   // 현재 depth의 크기 
    int cnt = 0;        // 현재 depth에서 몇 개의 노드 처리했는지 
    
    while (!q.empty()) {
        int now_node = q.front();
        q.pop();

        for (int next : tree[now_node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                parent[next] = now_node;    // 부모 노드 
                depth[next] = level;        // 노드 깊이 
            }
        }
        cnt++;
        if (cnt == now_size) {
            cnt = 0;
            now_size = q.size();
            level++;
        }
    }
}

int executeLCA(int a, int b) {
    // depth 맞추기
    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (depth[a] != depth[b]) {
        a = parent[a];
    }

    // 같은 조상 나올 때까지 함께 올라가기 
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    tree.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    bfs(1);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        int LCA = executeLCA(a, b);
        cout << LCA << '\n';
    }

    return 0;
}
