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
    int tc = 1; 

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> customers(N);

        for (int i = 0; i < N; i++) {
            cin >> customers[i];
        }
        sort(customers.begin(), customers.end());

        bool ok = true;

        for (int i = 0; i < N; i++) {
            int t = customers[i];
            int produced = (t / M) * K;
            int need = i + 1;

            if (produced < need) {
                ok = false;
                break;
            }
        }
        cout << "#" << tc << " " << (ok ? "Possible" : "Impossible") << "\n";
        tc++;
    }

    return 0;
}
