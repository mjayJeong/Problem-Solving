#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string X;
    cin >> X;

    int index = 0;

    for (int num = 1;; num++) {
        string s = to_string(num);
        
        for (char c : s) {
            if (index < X.size() && c == X[index]) {
                index++;
            }
        }

        if (index == X.size()){
            cout << num << '\n';
            break;
        }
    }

    return 0;
}
