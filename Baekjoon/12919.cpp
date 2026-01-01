#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool dfs(string cur, string target) 
{
    if (cur == target) return true;
    if (cur.size() < target.size()) return false;

    // 마지막 요소가 A면 A 제거
    if (cur[cur.size() - 1] == 'A') {
        string temp = cur;
        temp.pop_back();
        if (dfs(temp, target)) return true;
    }

    // 첫 요소가 B면 뒤집어진 건지 확인
    if (cur.front() == 'B') {
        string temp = cur;
        temp.erase(temp.begin());
        reverse(temp.begin(), temp.end());
        if (dfs(temp, target)) return true;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S, T;
    cin >> S >> T;

    if (dfs(T, S)) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}
