#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int q = s / n;
    int r = s % n;
    
    if (n > s) {
        answer.push_back(-1);
        return answer;
    }
    
    for (int i = 0; i < n-r; i++) {
        answer.push_back(q);
    }
    for (int i = 0; i < r; i++) {
        answer.push_back(q+1);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

// 몫을 n-r개, 몫+1을 r개로 배분하면 됨 
