#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    int max = 0; 
    for (int i = 0; i < N; i++) {
        if (max < arr[i].second - i) {
            max = arr[i].second - i;
        }
    }
    cout << max + 1;    

    return 0;
}
