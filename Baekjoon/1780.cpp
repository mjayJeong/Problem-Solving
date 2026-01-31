#include <iostream>
#include <vector>

using namespace std;

int answer[3] = {0, 0, 0};  // [-1, 0, 1] 개수 저장
vector<vector<int>> paper;

// 종이 모두 같은 수인지 확인 함수 
bool check_same(int r, int c, int size) {
    int cnt = paper[r][c];
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (cnt != paper[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// 종이 나누기
void divide_paper(int r, int c, int size) {
    if (check_same(r, c, size)) {
        answer[paper[r][c] + 1]++;  // -1->0, 0->1, 1->2
        return;
    }

    int new_size = size / 3;
    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            divide_paper(r + dx * new_size, c + dy * new_size, new_size);
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    paper.assign(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    divide_paper(0, 0, N);

    cout << answer[0] << "\n"; 
    cout << answer[1] << "\n"; 
    cout << answer[2] << "\n";

    return 0;
}
