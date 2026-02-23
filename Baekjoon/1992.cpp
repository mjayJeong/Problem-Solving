#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> video;
string answer;

// 모두 같은지 체크
bool check_same(int x, int y, int size)
{
    int first = video[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (video[i][j] != first) return false;
        }
    }
    return true;
}

// 출력 
void compress(int x, int y, int size) {
    if (check_same(x, y, size)) {
        answer += (video[x][y] ? '1' : '0');
        return;
    }

    int half = size / 2;
    answer += '(';
    compress(x, y, half);                 // 왼쪽 위
    compress(x, y + half, half);          // 오른쪽 위
    compress(x + half, y, half);          // 왼쪽 아래
    compress(x + half, y + half, half);   // 오른쪽 아래
    answer += ')';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    video.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            video[i][j] = line[j] - '0';
        }
    }

    compress(0, 0, N);

    cout << answer << '\n';

    return 0;
}
