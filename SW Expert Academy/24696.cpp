#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int boo = a * b * c;
        if (boo % 2 == 0) cout << 1 << '\n';
        else cout << 2 << '\n';
    }

    return 0;
}
