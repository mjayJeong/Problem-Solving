class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {-1, 1};
        int start = 0, end = 0, sum = sequence[0];
        int min_length = sequence.length + 1;
        
        while (end < sequence.length) {
            if (sum == k) {
                int window_size = end - start + 1;
                if (window_size < min_length) {
                    min_length = window_size;
                    answer = new int[] {start, end};
                }
                sum -= sequence[start];
                start++;
            } else if (sum < k) {
                end++;
                if (end < sequence.length) {
                    sum += sequence[end];
                }
            } else {
                sum -= sequence[start];
                start++;
            }
        }        
        
        return answer;
    }
}
