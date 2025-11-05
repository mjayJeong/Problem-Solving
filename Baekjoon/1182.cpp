#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> arr;
int answer = 0; 

void backtracking(int idx, int sum) 
{
    if (idx == N) {
        if (sum == S) answer++;
        return;
    }

    backtracking(idx + 1, sum + arr[idx]);      // idx 번째 원소 선택 
    backtracking(idx + 1, sum);                 // idx 번째 원소 선택 안함 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> S;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    backtracking(0, 0);

    if (S == 0) answer--;   // 공집합 제거 (크기가 양수인 부분수열만 허용)

    cout << answer << '\n';

    return 0; 
}
