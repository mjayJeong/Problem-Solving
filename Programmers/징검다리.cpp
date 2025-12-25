#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& rocks, int min_distance, int n) {
    int cnt = 0;
    int prev = rocks[0]; 

    for (int i = 1; i < rocks.size(); i++) {
        if (rocks[i] - prev < min_distance) {
            cnt++;     
            if (cnt > n) return false;      // 너무 많이 제거 -> 불가능
        } else {
            prev = rocks[i]; 
        }
    }
    return true;    // 제거 개수 n 이하면 가능
}

    
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0);
    rocks.push_back(distance);
    
    sort(rocks.begin(), rocks.end());
    
    int low = 1, high = distance;
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (check(rocks, mid, n)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return answer;
}
