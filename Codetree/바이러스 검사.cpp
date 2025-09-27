#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long leader, mem;
    cin >> n;
    vector<long long> rest(n);

    for (int i = 0; i < n; i++) {
        cin >> rest[i];
    }
    cin >> leader >> mem;

    long long answer = 0;
    for (int i = 0; i < n; i++) {
        rest[i] -= leader;
        answer++;
    }

    for (int i = 0; i < n; i++) {
        if (rest[i] <= 0) continue;
        if (rest[i] % mem == 0) answer += (rest[i] / mem);
        else answer += ((rest[i] / mem) + 1);
    }

    cout << answer;
    return 0;
}
