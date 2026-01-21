#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> family;
vector<bool> visited;
int one, two;
bool flag = false; 
int answer = 0; 

void dfs(int start) {
    if (flag) return; // 이미 찾았으면 중단

    if (start == two) {
        flag = true;
        cout << answer << '\n';
        return;
    }

    for (auto f : family[start]) {
        if (!visited[f]) {       
            visited[f] = true;
            answer++;
            dfs(f);
            answer--;
            visited[f] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> n;
    cin >> one >> two;
    cin >> m;
    family.resize(n+1);
    visited.resize(n+1, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }

    visited[one] = true;
    dfs(one);

    if (!flag) cout << -1 << '\n';

    return 0; 
}
