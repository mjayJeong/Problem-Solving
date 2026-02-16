#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        int x1, y1, p1, q1, x2, y2, p2, q2;
        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

        int overX = min(p1, p2) - max(x1, x2);  // x축 겹치는 길이
        int overY = min(q1, q2) - max(y1, y2);

        if (overX < 0 || overY < 0) cout << "d" << '\n';
        else if (overX > 0 && overY > 0) cout << "a" << "\n";
        else if (overX == 0 && overY == 0) cout << "c" << "\n";
        else cout << "b" << "\n";
    }

    return 0;
}
