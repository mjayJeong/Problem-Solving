#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
vector<char> dic;
vector<bool> visited;
string answer;

// 최소 1개 모음, 최소 2개 자음 체킹하는 함수
bool is_valid(string s) {
    int con = 0, vow = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vow++;
        } else {
            con++;
        }
    }
    if (vow >= 1 && con >= 2) return true;
    else return false;
}

// 백트래킹으로 가능한 경우의 수 만들기 
void backtracking(int start, int depth) {
    if (depth == L && is_valid(answer)) {
        cout << answer << '\n';
        return;
    }

    for (int i = start; i < dic.size(); i++) {
        visited[i] = true;
        answer.push_back(dic[i]);
        backtracking(i + 1, depth + 1);
        answer.pop_back();
        visited[i] = false;
    }

}

int main()
{
    cin >> L >> C;

    dic.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> dic[i];
    }
    sort(dic.begin(), dic.end());
    visited.assign(C, false);

    backtracking(0, 0);


    return 0; 
}
