#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long check(long long num, const vector<int> times)
{
    long long cnt = 0;
    for (int time : times) {
        cnt += num / time;
        if (cnt > 1000000000LL) break; // 너무 커지면 끊기
    }
    return cnt;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long low = 1;
    long long high = (long long)*max_element(times.begin(), times.end()) * (long long)n;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (check(mid, times) >= n) {
            answer = mid;        
            high = mid - 1;    
        } else {
            low = mid + 1;
        }
    }

    return answer;
}
