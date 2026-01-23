#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
vector<int> house;

bool canInstall(int d) {
    int cnt = 1; 
    int cur = house[0];
    for (int i = 1; i < N; i++) {
        int dist = house[i] - cur;
        if (dist >= d) {
            cur = house[i];
            cnt++;
        }
    }
    if (cnt >= C) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C;
    house.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> house[i];
    }
    sort(house.begin(), house.end());

    int answer = 0; 

    int left = 1, right = house[N-1] - house[0];
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canInstall(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
