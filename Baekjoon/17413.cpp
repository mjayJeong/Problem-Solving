#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> s1;
    string S;
    string result;
    getline(cin, S);

    bool inTag = false;
    
    for (int idx = 0; idx < S.length(); idx++) {
        if (S[idx] == '<') {
            while (!s1.empty()) {
                result.push_back(s1.top());
                s1.pop();
            }
            inTag = true;
            result.push_back('<');
        }
        else if (S[idx] == '>') {
            inTag = false;
            result.push_back(S[idx]);
        }
        else if (inTag) {
            result.push_back(S[idx]);
        }
        else {
            if (S[idx] == ' ') {
                while (!s1.empty()) {
                    result.push_back(s1.top());
                    s1.pop();
                }
                result.push_back(' ');
            }
            else {
                s1.push(S[idx]);
            }
        }
    }

    while (!s1.empty()) {
        result.push_back(s1.top());
        s1.pop();
    }

    cout << result;
    return 0;
}
