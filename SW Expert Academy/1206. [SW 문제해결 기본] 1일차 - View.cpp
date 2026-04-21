#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 10; i++) {
        int N;
        cin >> N;
        vector<int> building(N);
        for (int j = 0; j < N; j++) {
            cin >> building[j];
        }

        int answer = 0; 

        for (int i = 2; i < N-2; i++) {
            int mx = max({building[i-2], building[i-1], building[i+1], building[i+2]});
            if (building[i] > mx) answer += (building[i] - mx);
        }

        cout << "#" << i+1 << ' ' << answer << '\n';
    }


    return 0;
}
