#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, begin, end;
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        cin >> begin >> end;
        v.push_back({end, begin});
    }
    sort(v.begin(), v.end());

    int time = v[0].first;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (time <= v[i].second) {
            cnt++;
            time = v[i].first;
        }
    }
    cout << cnt;
    return 0;
}
