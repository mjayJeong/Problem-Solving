#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    vector<char> st;
    st.reserve(s.size());

    for (int i = 0; i < s.size(); i++) {
        st.push_back(s[i]); 

        if (st.size() >= 4) {
            int n = st.size();
            if (st[n-4] == 'P' && st[n-3] == 'P' && st[n-2] == 'A' && st[n-1] == 'P') {
                // PPAP -> P
                st.pop_back();
                st.pop_back();
                st.pop_back();
            }
        }
    }

    if (st.size() == 1 && st[0] == 'P') cout << "PPAP" << '\n';
    else cout << "NP" << '\n';

    return 0;
}
