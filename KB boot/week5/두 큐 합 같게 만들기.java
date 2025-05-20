import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        Deque<Integer> q1 = new ArrayDeque<>();
        Deque<Integer> q2 = new ArrayDeque<>();
        
        long sum1 = 0, sum2 = 0;
        
        for (int n : queue1) {
            q1.addLast(n);
            sum1 += n;
        }
        for (int n : queue2) {
            q2.addLast(n);
            sum2 += n;
        }
        
        int maxCount = queue1.length * 3;
        int count = 0;
        
        while (count <= maxCount) {
            if (sum1 == sum2) return count;
            
            if (sum1 > sum2) {
                int num = q1.pollFirst();
                sum1 -= num;
                sum2 += num;
                q2.addLast(num);
            } else {
                int num = q2.pollFirst();
                sum2 -= num;
                sum1 += num;
                q1.addLast(num);
            }
            count++;
        }
        return -1;
    }
}
