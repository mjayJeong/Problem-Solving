#include <iostream>
#include <vector>

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
        vector<int> stock(N);
        for (int i = 0; i < N; i++) {
            cin >> stock[i];
        }
        int maxPrice = stock[N-1];
        long long answer = 0; 

        for (int i = N-1; i >= 0; i--) {
            if (stock[i] < maxPrice) {
                answer += maxPrice - stock[i];
            } else {
                maxPrice = stock[i];
            }
        }

        cout << answer << '\n';

    }

    return 0;
}
