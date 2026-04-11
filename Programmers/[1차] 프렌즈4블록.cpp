#include <string>
#include <vector>

using namespace std;

int answer;
vector<vector<bool>> erase;

// 드롭 함수
void drop(int m, int n, vector<vector<char>>& new_board) {
    for (int j = 0; j < n; j++) {
        int write = m - 1;
        
        // 밑에서부터 올라오면서 문자 채우기
        for (int i = m - 1; i >= 0; i--) {
            if (new_board[i][j] != '.') {
                new_board[write][j] = new_board[i][j];
                write--;
            }
        }
        
        // 남은 윗부분은 . 으로 채우기
        while (write >= 0) {
            new_board[write][j] = '.';
            write--;
        }
    }
}

// 지우는 함수
void delete_block(int m, int n, vector<vector<char>>& new_board) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (erase[i][j] == true) {
                new_board[i][j] = '.';
                answer++;
            }
        }
    }
}


// 블록 검증 함수 
bool check_block(int m, int n, vector<vector<char>>& new_board) {
    bool flag = false;
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (new_board[i][j] != '.' &&
                new_board[i][j] == new_board[i][j+1] &&
                new_board[i][j] == new_board[i+1][j] &&
                new_board[i][j] == new_board[i+1][j+1]) {
                erase[i][j] = true;
                erase[i][j+1] = true;
                erase[i+1][j] = true;
                erase[i+1][j+1] = true;
                flag = true;
            }
        }
    }
    return flag;
}

int solution(int m, int n, vector<string> board) {
    answer = 0;
    
    vector<vector<char>> new_board(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            new_board[i][j] = board[i][j];
        }
    }
    
    while (true) {
        // 매번 지울 거 초기화
        erase.assign(m, vector<bool>(n, false));
        
        // 지울 거 체크 -> 있으면 
        if (check_block(m, n, new_board)) {
            delete_block(m, n, new_board);
            drop(m, n, new_board);
        } else {
            break;
        }
    }

    return answer;
}
