#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int max_value = *max_element(tangerine.begin(), tangerine.end());
    
    vector<int> cnt(max_value + 1, 0);
    
    // 카운팅 배열에 각 숫자 개수 저장
    for (int i = 0; i < tangerine.size(); i++) {
        cnt[tangerine[i]]++;
    }
    
    // pq에 개수 많은 순으로 저장
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= max_value; i++) {
        pq.push({cnt[i], i});
    }
    
    int now = 0;
    while (now < k) {
        auto [num, id] = pq.top();
        pq.pop();
        
        now += num;
        answer++;
    }
    
    
    return answer;
}
