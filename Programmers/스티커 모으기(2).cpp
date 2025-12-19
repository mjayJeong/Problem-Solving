#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int dp_one[100001], dp_not[100001];
    int n = sticker.size();
    
    // 예외 처리 
    if (n == 1) return sticker[0];
    if (n == 2) return max(sticker[0], sticker[1]);
    
    // 1. 첫 번째 스티커 뜯는 경우 
    dp_one[0] = sticker[0];
    dp_one[1] = dp_one[0];
    for (int i = 2; i < n-1; i++) {
        dp_one[i] = max(dp_one[i-2] + sticker[i], dp_one[i-1]);
    }
    
    // 2. 첫 번째 스티커 안 뜯는 경우 
    dp_not[0] = 0;
    dp_not[1] = sticker[1];
    for (int i = 2; i < n; i++) {
        dp_not[i] = max(dp_not[i-2] + sticker[i], dp_not[i-1]);
    }
    
    // 3. 비교 후 결과 
    answer = max(dp_one[n-2], dp_not[n-1]);

    return answer;
}
