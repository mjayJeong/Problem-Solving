#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> K;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < K; i++) {
            int n;
            cin >> n;
            pq.push(n);
        }
        long long answer = 0;
        while (pq.size() >= 2) {
            long long cnt = 0;
            // pq에서 작은 것부터 빼면서 더하고 다시 넣기
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            cnt = a + b;
            pq.push(cnt);
            answer += cnt;
        }
        cout << answer << "\n";
    }

    return 0;
}
