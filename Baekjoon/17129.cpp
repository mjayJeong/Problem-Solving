#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define MAX 3001

using namespace std;

int n, m;
int grid[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

int bfs(int start_x, int start_y) 
{
    visited[start_x][start_y] = 1;
    q.push(make_pair(start_x, start_y));
    dist[start_x][start_y] = 0;   

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if (grid[x][y] == 3 || grid[x][y] == 4 || grid[x][y] == 5) {
            return dist[x][y];
        } 

        for (int i = 0; i < 4; i++) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if (x_new >= 0 && x_new < n && y_new >= 0 && y_new < m && !visited[x_new][y_new] && grid[x_new][y_new] != 1) {
                visited[x_new][y_new] = 1;
                q.push(make_pair(x_new, y_new));
                dist[x_new][y_new] = dist[x][y] + 1;
            }
        }
    }
    return -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; 
    int x, y;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < m; j++) {
            grid[i][j] = row[j] - '0';
            if (grid[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }
    int answer = bfs(x, y);
    if (answer == -1) {
        cout << "NIE\n";
    } else {
        cout << "TAK\n" << answer << '\n';
    }


    return 0;
}
