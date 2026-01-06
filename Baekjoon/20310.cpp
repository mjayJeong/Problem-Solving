#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;

    int zero_cnt = 0, one_cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '0') zero_cnt++;
        else one_cnt++;
    }

    // 삭제해야 할 양
    zero_cnt /= 2;
    one_cnt /= 2;

    // 1은 앞에서부터 삭제 
    for (int i = 0; i < S.size(); i++) {
        if (one_cnt == 0) break;
        if (S[i] == '1') { 
            S.erase(S.begin() + i);
            one_cnt--;
            i--;
        }
    }

    // 0은 뒤에서부터 삭제 
    for (int i = S.size() - 1; i >= 0; i--) {
        if (zero_cnt == 0) break;
        if (S[i] == '0') {
            S.erase(S.begin() + i);
            zero_cnt--;
        }
    }

    cout << S << '\n';

    return 0;
}
