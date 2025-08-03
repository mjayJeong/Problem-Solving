#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[100001];
vector<int> stones;
int n;

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int cnt = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        int jump = stones[x];

        int left = x - jump;
        if (left >= 0 && !visited[left]) {
            visited[left] = true;
            q.push(left);
            cnt++;
        }

        int right = x + jump;
        if (right < n && !visited[right]) {
            visited[right] = true;
            q.push(right);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int s;
    cin >> n;

    stones.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    cin >> s;
    s--;

    int result = bfs(s);
    cout << result << '\n';


    return 0;
}
