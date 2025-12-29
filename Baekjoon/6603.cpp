#include <iostream>
#include <vector>

using namespace std;

vector<int> subset;
vector<int> answer;

void backtracking(int start, int depth)
{
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = start; i < subset.size(); i++) {
        answer[depth] = subset[i];
        backtracking(i + 1, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int k;
        cin >> k;
        if (k == 0) {
            break;
        }

        subset.resize(k);
        answer.resize(6);

        for (int i = 0; i < k; i++) {
            cin >> subset[i];
        }

        backtracking(0, 0);
        cout << '\n';
    }

    return 0;
}
