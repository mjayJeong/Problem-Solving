#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> title(N);
    vector<int> upper(N);

    for (int i = 0; i < N; i++) {
        cin >> title[i] >> upper[i];
    }

    while (M--) {
        int power;
        cin >> power;

        int idx = lower_bound(upper.begin(), upper.end(), power) - upper.begin();
        cout << title[idx] << "\n";
    }

    return 0;
}
