#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0; 
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int one = 0, two = 0;

    while (one < A.size() && two < B.size()) { 
        if (A[one] < B[two]) {
            answer++;
            one++;  
            two++;
        } else {
            two++; 
        }
    }

    return answer;
}
