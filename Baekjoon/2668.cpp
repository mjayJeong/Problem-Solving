#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> graph;
vector<int> result;

void dfs(int start) 
{
    vector<bool> visited(N + 1, false);
    int cur = start;

    while (!visited[cur]) {
        visited[cur] = true;
        cur = graph[cur];
    }

    if (cur == start) {
        result.push_back(start);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    graph.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> graph[i];
    }

    for (int i = 1; i <= N; i++) {
        dfs(i);
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    
    
    return 0;
}
