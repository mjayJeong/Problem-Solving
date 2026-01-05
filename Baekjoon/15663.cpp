#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M; 
vector<int> arr;
vector<bool> visited;
vector<int> answer;

void backtracking(int start, int depth) 
{
    if (depth == M) {
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int prev = -1;  // depth에서 중복 방지 
    for (int i = 0; i < arr.size(); i++) {
        if (prev != arr[i] && !visited[i]) {
            visited[i] = true;
            answer.push_back(arr[i]);
            prev = arr[i];

            backtracking(start + i, depth + 1);

            answer.pop_back();
            visited[i] = false;
        }
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
    visited.resize(N + 1, false);

    sort(arr.begin(), arr.end());

    backtracking(arr[0], 0);

    return 0;
}
