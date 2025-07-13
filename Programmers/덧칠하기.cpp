#include <vector>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int idx = 0;
    int len = section.size();
    
    while (idx < len) {
        int start = section[idx];
        answer++; 
        while (idx < len && section[idx] < start + m) {
            idx++;
        }
    }
    return answer;
}
