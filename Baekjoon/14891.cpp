#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

void rotateClockwise(deque<int>& gear) {
    int t = gear.back();
    gear.pop_back();
    gear.push_front(t);
}

void rotateCounterClockwise(deque<int>& gear) {
    int t = gear.front();
    gear.pop_front();
    gear.push_back(t);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<deque<int>> gear(4);

    for (int i = 0; i < 4; i++) {
        string state;
        cin >> state;
        for (char c : state) {
            gear[i].push_back(c - '0');
        }
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++) {
        int num, dir;
        cin >> num >> dir;
        num--;

        vector<int> rotate(4, 0);  // 각 톱니바퀴 돌릴 방향
        rotate[num] = dir;

        // 왼쪽
        for (int j = num-1; j >= 0; j--) {
            if (gear[j][2] != gear[j+1][6]) rotate[j] = -rotate[j + 1];
            else break;
        }
        // 오른쪽
        for (int j = num+1; j < 4; j++) {
            if (gear[j-1][2] != gear[j][6]) rotate[j] = -rotate[j - 1];
            else break;
        }

        for (int j = 0; j < 4; j++) {
            if (rotate[j] == 1) rotateClockwise(gear[j]);
            else if (rotate[j] == -1) rotateCounterClockwise(gear[j]);
        }
    }

    int answer = 0; 
    for (int i = 0; i < 4; i++) {
        if (gear[i][0] == 1) answer += (1 << i);
    }
    cout << answer << '\n';

    return 0;
}
