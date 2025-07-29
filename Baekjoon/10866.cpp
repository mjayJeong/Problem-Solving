#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    deque<int> DQ;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string command;
        int num;
        cin >> command;

        if (command == "push_front") {
            cin >> num;
            DQ.push_front(num);
        } else if (command == "push_back") {
            cin >> num;
            DQ.push_back(num);
        } else if (command == "pop_front") {
            if (DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        } else if (command == "pop_back") {
            if (DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        } else if (command == "size") {
            cout << DQ.size() << '\n';
        } else if (command == "empty") {
            cout << (DQ.empty() ? 1 : 0) << '\n';
        } else if (command == "front") {
            if (DQ.empty()) cout << -1 << '\n';
            else cout << DQ.front() << '\n';
        } else if (command == "back") {
            if (DQ.empty()) cout << -1 << '\n';
            else cout << DQ.back() << '\n';
        } 
    }
    return 0;
}
