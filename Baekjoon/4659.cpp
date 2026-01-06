#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        string pw;
        cin >> pw;

        if (pw == "end") break;

        bool vowel_used = false;
        bool ok = true;

        int vowel_cnt = 0; 
        int cons_cnt = 0;

        for (int i = 0; i < pw.size(); i++) {
            // 1. 모음 포함 여부
            if (isVowel(pw[i])) {
                vowel_used = true;
            }

            // 2. 3개 연속 모음/자음
            if (isVowel(pw[i])) {
                vowel_cnt++;
                cons_cnt = 0; 
            } else {
                cons_cnt++;
                vowel_cnt = 0;
            }

            if (vowel_cnt == 3 || cons_cnt == 3) {
                ok = false;
                break;
            }

            // 3. 같은 글자 2번 연속 체크
            if (i > 0 && pw[i] == pw[i-1]) {
                if (!(pw[i] == 'e' || pw[i] == 'o')) {
                    ok = false;
                    break;
                }
            }
        }
        if (!vowel_used) ok = false;

        if (ok) cout << "<" << pw << "> is acceptable.\n";
        else cout << "<" << pw << "> is not acceptable.\n";

    }

    return 0;
}
