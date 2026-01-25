#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 10;
    int idx = 1;

    while (T--) {
        int n;
        cin >> n;
        vector<int> height(100);
        for (int i = 0; i < 100; i++) {
            cin >> height[i];
        }
        sort(height.begin(), height.end());

        while (n--) {
            if (height[99] - height[0] == 0 || height[99] - height[0] == 0) break;
            height[0] += 1;
            height[99] -= 1;
            sort(height.begin(), height.end());
        }
        cout << "#" << idx << " " << height[99] - height[0] << "\n";
        idx++;
    }

    return 0;
}
