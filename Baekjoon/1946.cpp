#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end());

        int answer = 1;
        int bestInterview = v[0].second;

        for (int i = 1; i < N; i++) {
            if (v[i].second < bestInterview) {
                answer++;
                bestInterview = v[i].second;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
