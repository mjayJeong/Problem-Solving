#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int> st;
    for (int i = 0; i < ingredient.size(); i++) {
        st.push_back(ingredient[i]);
        int n = st.size();
        
        if (st.size() >= 4) {       // 스택 사이즈 4 이상이면 위에 4개 비교
            if (st[n-1] == 1 && st[n-2] == 3 && st[n-3] == 2 && st[n-4] == 1) {
                answer++;
                st.pop_back();
                st.pop_back();
                st.pop_back();
                st.pop_back();
            }
        }
    }
    
    return answer;
}

// 빵 : 1, 야채 : 2, 고기 : 3
