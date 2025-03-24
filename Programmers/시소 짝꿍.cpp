#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> cnt(1001, 0);
    
    // 카운트 배열에 무게 추가
    for (int i = 0; i < weights.size(); i++) {
        cnt[weights[i]]++;
    }
    
    // 몸무게를 3/2, 4/3, 2배 비율로 고치고 cnt 배열에 있으면 count
    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] % 2 == 0) {
            long long tmp = (weights[i] / 2) * 3;
            if (tmp <= 1000) answer += cnt[tmp];
        }
        if (weights[i] % 3 == 0) {
            long long tmp = (weights[i] / 3) * 4;
            if (tmp <= 1000) answer += cnt[tmp];
        }
        long long tmp = (weights[i] * 2);
        if (tmp <= 1000) answer += cnt[tmp];
    }
    
    // 몸무게 같은 경우 
    for (int i = 100; i < 1001; i++) {   // 몸무게는 100부터 시작
        if (cnt[i] >= 2) {
            answer += (long long)(cnt[i] * (cnt[i]-1)) / 2;   // 2명 뽑는 n(n-1)/2 공식
        }
    }
  
    return answer;
}
