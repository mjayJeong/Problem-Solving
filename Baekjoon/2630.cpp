#include <iostream>

using namespace std;

int n;
int grid[128][128];
int white = 0;
int blue = 0;

// 모든 색깔이 같은지 판별하는 함수
bool isUniform(int r, int c, int sz) {
    int color = grid[r][c];
    for (int i = r; i < r + sz; i++) {
        for (int j = c; j < c + sz; j++) {
            if (color != grid[i][j]) return false;
        }
    }
    return true;
}

// 구간 절반으로 나누는 함수
void cut(int r, int c, int sz) {
    if (isUniform(r, c, sz)) {
        if (grid[r][c] == 0) ++white;
        else ++blue;
        return;
    }
    int h = sz / 2;
    cut(r, c, h);
    cut(r, c + h, h);
    cut(r + h, c, h);
    cut(r + h, c + h, h);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cut(0, 0, n);

    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}
