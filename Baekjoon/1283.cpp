#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    cin.ignore();               // getline 전에 필요

    vector<string> options(N);
    vector<bool> used(26, false);

    for (int i = 0; i < N; i++) {
        string op;
        getline(cin, op);
 
        int idx = -1;

        // 1. 첫 글자 체크
        for (int j = 0; j < op.size(); j++) {
            if (j == 0 || op[j - 1] == ' ') {
                char c = toupper(op[j]);
                if ('A' <= c && c <= 'Z' && !used[c - 'A']) {
                    used[c - 'A'] = true;
                    idx = j;
                    break;
                }
            }
        }

        // 2. 전체 문자 체크
        if (idx == -1) {
            for (int j = 0; j < op.size(); j++) {
                if (op[j] == ' ') continue;
                char c = toupper(op[j]);
                if ('A' <= c && c <= 'Z' && !used[c - 'A']) {
                    used[c - 'A'] = true;
                    idx = j;
                    break;
                }
            }
        }

        // 출력 부분
        if (idx == -1) {
            cout << op << '\n';
        } else {
            for (int j = 0; j < op.size(); j++) {
                if (j == idx) cout << '[' << op[j] << ']';
                else cout << op[j];
            }
            cout << '\n';
        }
    }

    return 0;
}
