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
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int answer = 0;

    for (int i = 0; i < N; i++) {
        int left = 0, right = N-1;
        
        while (left < right) {
            if (left == i) { 
                left++; 
                continue; 
            }
            if (right == i) { 
                right--; 
                continue; 
            }

            if (arr[left] + arr[right] > arr[i]) {
                right--;
            } else if (arr[left] + arr[right] < arr[i]) {
                left++;
            } else {
                answer++;
                break;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}
