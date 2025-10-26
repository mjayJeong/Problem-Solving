#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string word;
    cin >> word;
    int M;
    cin >> M;

    list<char> L(word.begin(), word.end());
    auto cur = L.end();

    while (M--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (cur != L.begin()) {
                cur--;
            }
        } else if (cmd == 'D') {
            if (cur != L.end()) {
                cur++;
            }
        } else if (cmd == 'B') {
            if (cur != L.begin()) {
                cur = L.erase(prev(cur));
            }
        } else if (cmd == 'P') {
            char x;
            cin >> x;
            L.insert(cur, x);
        }
    }

    for (char c : L) {
        cout << c;
    }
    
    return 0;
}
