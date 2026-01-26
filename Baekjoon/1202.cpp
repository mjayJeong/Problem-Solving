#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> jewel(N); 
    for (int i = 0; i < N; i++) cin >> jewel[i].first >> jewel[i].second;

    vector<int> bag(K);
    for (int i = 0; i < K; i++) cin >> bag[i];

    sort(jewel.begin(), jewel.end()); 
    sort(bag.begin(), bag.end());   

    priority_queue<int> pq; 
    long long ans = 0;
    int j = 0;

    for (int i = 0; i < K; i++) {
        int cap = bag[i];

        while (j < N && jewel[j].first <= cap) {
            pq.push(jewel[j].second);
            j++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";
    return 0;
}
