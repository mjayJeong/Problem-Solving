#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, bomb;
    cin >> s >> bomb;

    string answer;
    int size = bomb.size();
    
    for (char c : s) {
        answer.push_back(c);

        if (answer.size() >= size) {
            bool match = true;
            for (int i = 0; i < size; i++) {
                if (answer[answer.size() - size + i] != bomb[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                for (int i = 0; i < size; i++) {
                    answer.pop_back();
                }
            }
        }
    }
    if (answer.empty()) cout << "FRULA";
    else cout << answer;

    return 0; 
}
