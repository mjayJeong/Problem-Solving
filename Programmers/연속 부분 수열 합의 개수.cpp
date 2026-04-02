#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    int n = elements.size();
    
    // 2배로 확장
    vector<int> extended = elements;
    extended.insert(extended.end(), elements.begin(), elements.end());
    
    for (int len = 1; len <= n; len++) {
        for (int start = 0; start < n; start++) {
            int sum = 0; 
            for (int k = start; k < start + len; k++) {
                sum += extended[k];
            }
            s.insert(sum);
        }
    }
    return s.size();
}
