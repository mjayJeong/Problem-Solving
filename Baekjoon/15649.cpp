#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> answer;
bool visited[10];

void backtracking(int start, int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        answer[depth] = i;
        backtracking(start + 1, depth + 1);
        visited[i] = false;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    answer.resize(9);

    backtracking(0, 0);

    return 0;
}
