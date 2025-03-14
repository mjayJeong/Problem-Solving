#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxHeight(vector<int>& tree, int n, int m) {
    int start = 0, end = *max_element(tree.begin(), tree.end());
    int answer = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        long long sum = 0;

        for (int height : tree) {
            if (height > mid) sum += height - mid;
        }

        if (sum < m) {
            end = mid - 1;
        } else {
            answer = mid;
            start = mid + 1;
        }
    }
    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> tree(n);

    for (int& t : tree) cin >> t;

    cout << getMaxHeight(tree, n, m) << '\n';
    return 0;
}
