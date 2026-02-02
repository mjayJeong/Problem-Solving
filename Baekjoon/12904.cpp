#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S, T;
    cin >> S >> T;  

    while (T.size() > S.size()) {
        // 문자열 뒤에 A 추가하는 거 반대로
        if (T.back() == 'A') {
            T.pop_back();
        } else {
            // 문자열 뒤집고 뒤에 B 추가하는 거 반대로
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    if (T.compare(S) == 0) cout << 1 << '\n';
    else cout << 0 << '\n';


    return 0;
}
