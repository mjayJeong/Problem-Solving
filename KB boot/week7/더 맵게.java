import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int s : scoville) {
            pq.add(s);
        }

        while (pq.size() >= 2 && pq.peek() < K) {
            int a = pq.poll();
            int b = pq.poll();
            int mixed = a + (b * 2);
            pq.add(mixed);
            answer++;
        }

        if (pq.peek() < K) return -1;

        return answer;
    }
}
