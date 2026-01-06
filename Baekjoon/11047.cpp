#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int answer = 0;
    for (int i = N-1; i >= 0; i--) {
        if (K == 0) break;
        if (coins[i] <= K) {
            int cnt = K / coins[i]; 
            K = K - cnt * coins[i];
            answer += cnt;
        }
    }

    cout << answer << '\n';

    return 0;
}
