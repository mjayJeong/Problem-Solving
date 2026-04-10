#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } 

            if (s[i] == ')') {
                if (st.empty()) return false;
                char tmp = st.top();
                if (tmp != '(') return false;
                st.pop();
            } else if (s[i] == ']') {
                if (st.empty()) return false;
                char tmp = st.top();
                if (tmp != '[') return false;
                st.pop();
            } if (s[i] == '}') {
                if (st.empty()) return false;
                char tmp = st.top();
                if (tmp != '{') return false;
                st.pop();
            } 
        }

        if (!st.empty()) return false;
        return true;
    }
};
