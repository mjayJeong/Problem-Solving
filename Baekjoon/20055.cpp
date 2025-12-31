#include <iostream>
#include <vector>

using namespace std;

int N, K;

// 내구도 K개 이상인지 검토
bool check_durability(vector<int>& v) {
    int cnt = 0;
    for (int i = 0; i < 2*N; i++) {
        if (v[i] == 0) cnt++;
    }

    if (cnt >= K) return true;
    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    
    vector<int> durability(2*N);
    for (int i = 0; i < 2*N; i++) {
        cin >> durability[i];
    }

    vector<bool> robot(N, false);       // 로봇은 위칸에만 존재

    int step = 0; 

    while (true) {
        step++;

        // 1. 벨트 회전
        int last = durability[2*N - 1];
        for (int i = 2*N - 1; i >= 1; i--) {
            durability[i] = durability[i-1];
        }
        durability[0] = last;

        // 로봇도 회전
        for (int i = N - 1; i >= 1; i--) {
            robot[i] = robot[i-1];
        }
        robot[0] = false;       // 올리는 위치에 추가 x
        robot[N-1] = false;     // 내리는 위치에서 바로 내림

        // 2. 로봇 이동 
        for (int i = N - 2; i >= 0; i--) {
            if (robot[i] && !robot[i+1] && durability[i+1] > 0) {
                robot[i] = false;
                robot[i+1] = true;
                durability[i+1]--;
            }
        }
        robot[N - 1] = false;    // 내리는 위치면 바로 내림

        // 3. 로봇 올리기
        if (durability[0] > 0) {
            robot[0] = true;
            durability[0]--;
        }

        // 4. 종료 조건 확인
        if (check_durability(durability)) break;
    }
    cout << step << '\n';

    return 0;
}
