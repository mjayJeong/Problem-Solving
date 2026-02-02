#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> answer;

void backtracking(int start, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << ' ';
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int i = start; i < N; i++) {
        if (prev == arr[i]) continue; 
        prev = arr[i];

        answer.push_back(arr[i]);
        backtracking(i, depth + 1);    
        answer.pop_back();           
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    backtracking(0, 0);

    return 0;
}
