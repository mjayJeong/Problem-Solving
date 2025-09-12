#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int cum = v[0];
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += cum;
        cum += v[i];
    }

    cout << answer;

    return 0;
}
