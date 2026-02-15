#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int>> v;
vector<int> arr;
int answer = INT_MAX;

int calcTeam(vector<int>& team) {
    int sum = 0;
    int m = team.size();

    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            int a = team[i], b = team[j];
            sum += v[a][b] + v[b][a];
        }
    }
    return sum;
}

// 업무 강도 차이 구하는 함수 
void get_work() {
    vector<bool> isMorning(n, false);
    for (int x : arr) isMorning[x] = true;

    vector<int> evening;
    evening.reserve(n/2);
    // 아침에 포함 안된 일들은 저녁에 넣기 
    for (int i = 0; i < n; i++) {
        if (!isMorning[i]) evening.push_back(i);
    }

    // arr 배열 vs 선택 안 된 애들 두 개 차이 
    int s1 = calcTeam(arr);
    int s2 = calcTeam(evening);

    answer = min(answer, abs(s1 - s2));
}

// 경우의 수 만들기 
void backtracking(int start, int depth) 
{
    if (depth == n/2) {
        get_work();
        return;
    }

    for (int i = start; i < n; i++) {
        arr.push_back(i);
        backtracking(i + 1, depth + 1);
        arr.pop_back();
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    v.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    // 0번을 아침에 고정 -> 대칭 중복 제거
    arr.push_back(0);
    backtracking(1, 1);

    cout << answer << '\n';

    return 0;
}
