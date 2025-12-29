#include <iostream>
#include <vector>

using namespace std;

int compare(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first && a.second > b.second) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> people(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        people[i] = {x, y};
    }

    vector<int> rank(N, 1);

    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            if (compare(people[j], people[i])) cnt++;
        }
        rank[i] = cnt + 1;
    }

    for (int i = 0; i < N; i++) {
        cout << rank[i] << ' ';
    }

    return 0;
}
