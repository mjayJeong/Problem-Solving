#include <string>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int answer;

void get_color(vector<vector<string>>& board, int h, int w) {
    string cur = board[h][w];
    int N = board.size();
    
    for (int d = 0; d < 4; d++) {
        int nh = h + dx[d];
        int nw = w + dy[d];
        
        if (nh < 0 || nh >= N || nw < 0 || nw >= N) continue;
        if (board[nh][nw] == cur) answer++;
    }
}

int solution(vector<vector<string>> board, int h, int w) {
    answer = 0;
    
    get_color(board, h, w);
    
    return answer;
}
