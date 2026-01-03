#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<bool> visited;
vector<int> answer;

void backtracking(vector<int> &v, int start, int depth)
{
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            answer.push_back(v[i]);
            backtracking(v, i+1, depth+1);
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
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    visited.resize(N, false);

    backtracking(arr, 0, 0);

    return 0;
}
