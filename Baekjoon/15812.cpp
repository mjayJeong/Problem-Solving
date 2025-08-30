#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;  
    string s;
    vector<pair<int,int>> empties;   
    vector<pair<int,int>> villages;  

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '0') empties.push_back({i, j});
            else villages.push_back({i, j});
        }
    }

    int size = empties.size();
    int answer = INT_MAX;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            auto [r1, c1] = empties[i];
            auto [r2, c2] = empties[j];

            int worst = 0;
            for (auto [vr, vc] : villages) {
                int d1 = abs(vr - r1) + abs(vc - c1);
                int d2 = abs(vr - r2) + abs(vc - c2);
                int tmp = min(d1, d2);
                worst = max(worst, tmp);
                if (worst >= answer) break;
            }
            answer = min(answer, worst);
        }
    }
    cout << answer << '\n';

    return 0;
}
