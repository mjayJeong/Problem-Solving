#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> checked;   // 체크되었는지 확인 

// 빙고판 숫자 제거 
void delete_num(int num) {
    // 같은 숫자 체크
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (num == board[i][j]) {
                checked[i][j] = true;
            }
        }
    }
}

// 빙고판 완성 검사 
bool completed() {
    int cnt = 0;

    // 가로 5줄
    for (int i = 0; i < 5; i++) {
        if (checked[i][0] && checked[i][1] && checked[i][2] && checked[i][3] && checked[i][4]) {
            cnt++;
        }
    }

    // 세로 5줄
    for (int i = 0; i < 5; i++) {
        if (checked[0][i] && checked[1][i] && checked[2][i] && checked[3][i] && checked[4][i]) {
            cnt++;
        }
    }

    // 대각선 2줄
    if (checked[0][0] && checked[1][1] && checked[2][2] && checked[3][3] && checked[4][4]) cnt++;
    if (checked[0][4] && checked[1][3] && checked[2][2] && checked[3][1] && checked[4][0]) cnt++;

    return cnt >= 3;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    board.resize(5, vector<int>(5));
    vector<vector<int>> order(5, vector<int>(5));
    checked.assign(5, vector<bool>(5, false));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> order[i][j];
        }
    }

    int answer = 0;
    // 숫자 제거 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            delete_num(order[i][j]);
            answer++;
            if (completed()) {
                cout << answer << '\n';
                return 0;
            }
        }
    }
    return 0;
}
