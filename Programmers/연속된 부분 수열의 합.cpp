#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {-1, -1};
    int start = 0, end = 0, sum = sequence[0];
    int min_length = sequence.size() + 1;

    while (end < sequence.size()) {
        if (sum == k) {
            int window_size = end - start + 1;
            if (window_size < min_length) {
                min_length = window_size;
                answer = {start, end};
            }
            sum -= sequence[start];
            start++;
        } else if (sum < k) {
            end++;
            if (end < sequence.size()) {
                sum += sequence[end];
            }
        } else {
            sum -= sequence[start];
            start++;
        }
    }

    return answer;
}
