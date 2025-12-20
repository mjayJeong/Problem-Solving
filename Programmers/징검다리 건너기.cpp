#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool canCross(const vector<int>& stones, int k, int x) {
    int cnt = 0;
    for (int s : stones) {
        if (s < x) cnt++;
        else cnt = 0;
        if (cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int low = 1, high = *max_element(stones.begin(), stones.end());

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canCross(stones, k, mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return answer;
}
