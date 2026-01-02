#include <iostream>
#include <vector>

using namespace std;

int N, M;
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

    for (int i = start; i <= N; i++) {
        answer.push_back(i);
        backtracking(i, depth + 1);
        answer.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    backtracking(1, 0);

    return 0;
}
