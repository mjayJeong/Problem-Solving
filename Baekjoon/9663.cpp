#include <iostream>
#include <vector>

using namespace std;

vector<int> col;
int N;
int answer = 0;

bool check(int level) {
    for (int i = 0; i < level; i++) {
        // 대각선이거나 같은 라인 
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i) {
            return false;
        }
    }
    return true;
}

void nqueen(int x) {
    if (x == N) {
        answer++;
    } else {
        for(int i = 0; i < N; i++) {
            col[x] = i;     // 해당 위치에 퀸 배치
            if (check(x)) {
                nqueen(x+1);
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    col.resize(N);
    
    nqueen(0);
    cout << answer << '\n';

    return 0;
}
