#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    int sum = 0;
    int idx = 0;
    sort(d.begin(), d.end());
    
    while (idx < d.size() && sum < budget) {
        if (sum + d[idx] > budget) break;
        sum += d[idx];
        idx++;
        answer++;
    }
    
    return answer;
}
