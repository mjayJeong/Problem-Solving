#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    const int n = (int)name.size();

    // 1) 문자 바꾸는 횟수
    int upDown = 0;
    for (char c : name) {
        upDown += min(c - 'A', 'Z' - c + 1);
    }

    // 2) 커서 이동 최소값
    // 기본은 직진: n-1
    int move = n - 1;

    // i 지점 이후의 연속 'A' 구간을 건너뛰는 전략을 모두 시험
    for (int i = 0; i < n; ++i) {
        int next = i + 1;
        while (next < n && name[next] == 'A') next++;

        // 두 가지 우회 케이스:
        // a. 오른쪽으로 i까지 갔다가 되돌아가서 끝쪽으로 가기: 2*i + (n - next)
        // b. 끝쪽으로 갔다가 되돌아와 i 다음으로 오기: i + 2*(n - next)
        move = min(move, 2*i + (n - next));
        move = min(move, i + 2*(n - next));
    }

    return upDown + move;
}
