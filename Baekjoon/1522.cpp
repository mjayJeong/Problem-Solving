#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    // A 개수 카운팅
    int cntA = 0; 
    for (char c : s) {
        if (c == 'a') cntA++;
    }

    if (cntA == 0 || cntA == n) {
        cout << 0 << '\n';
        return 0;
    }

    string s2 = s + s;

    // 초기 윈도우 안에 B 개수 카운팅
    int cntB = 0;
    for (int i = 0; i < cntA; i++) {
        if (s2[i] == 'b') cntB++;
    }

    int answer = cntB;

    for (int start = 1; start < n; start++) {
        // 빠지는 문자
        if (s2[start-1] == 'b') cntB--;
        // 들어오는 문자
        if (s2[start + cntA - 1] == 'b') cntB++;

        answer = min(answer, cntB);
    }   

    cout << answer << '\n';

    return 0;
}
