#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<char>> map;
vector<vector<int>> dist;

int bfs(int start_x, int start_y)
{
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (map[x][y] == 'G') {
            return dist[x][y];
        }
        
        for (int d = 0; d < 4; d++) {
            int nx = x;
            int ny = y;
            
            while (true) {
                int tx = nx + dx[d];
                int ty = ny + dy[d];
                
                if (tx < 0 || tx >= N || ty < 0 || ty >= M) break;
                if (map[tx][ty] == 'D') break;
                
                nx = tx;
                ny = ty;
            }
            
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int solution(vector<string> board) {
    N = board.size();
    M = board[0].size();
    
    map.assign(N, vector<char>(M));
    dist.assign(N, vector<int>(M, -1));
    
    pair<int, int> start;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = board[i][j];
            if (map[i][j] == 'R') {
                start.first = i;
                start.second = j;
            } 
        }
    }
        
    return bfs(start.first, start.second);
}
