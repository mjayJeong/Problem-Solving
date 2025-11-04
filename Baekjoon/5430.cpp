#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string order;
        cin >> order;
        int n;
        cin >> n;
        string arr;
        cin >> arr;

        int answer = 0;

        // vector에 넣기 
        vector<int> v;
        int num = 0;
        bool inNum = false;
        for (char c : arr) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                inNum = true;
            } else if (inNum) {
                v.push_back(num);
                num = 0; 
                inNum = false;
            }
        }
        // 문자열 끝이 숫자로 끝나도 처리
        if (inNum) v.push_back(num);

        // flag 이용해서 연산 줄이기 
        bool reversed = false;
        bool error = false;
        // 유효 구간은 입력 n이 아니라 실제 파싱 길이 기반
        int front = 0, back = (int)v.size();

        for (char cmd : order) {
            if (cmd == 'R') {
                reversed = !reversed;
            } else if (cmd == 'D') {
                if (front >= back) {
                    cout << "error\n";
                    error = true;
                    break;
                }
                if (!reversed) front++;
                else back--;
            }
        }

        if (error) continue;

        // 출력하는 부분 
        cout << '[';
        if (front < back) {
            if (!reversed) {
                for (int j = front; j < back; j++) {
                    cout << v[j];
                    if (j != back - 1) cout << ',';
                }
            } else {
                for (int j = back - 1; j >= front; j--) {
                    cout << v[j];
                    if (j != front) cout << ',';
                }
            }
        }
        cout << "]\n";
    }

    return 0;
}
