#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int max_sum = 0;

    do {
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += abs(v[i] - v[i+1]);
        }
        max_sum = max(max_sum, sum);
    } while (next_permutation(v.begin(), v.end()));

    cout << max_sum << '\n';

    return 0;
}
