import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> queue = new LinkedList<>();
        int[] tempAnswer = new int[progresses.length];  
        int idx = 0;

        for (int i = 0; i < progresses.length; i++) {
            int remaining = 100 - progresses[i];
            int requiredDays = (remaining + speeds[i] - 1) / speeds[i];
            queue.offer(requiredDays);
        }

        while (!queue.isEmpty()) {
            int first = queue.poll();
            int count = 1;

            while (!queue.isEmpty() && queue.peek() <= first) {
                queue.poll();
                count++;
            }

            tempAnswer[idx++] = count;
        }

        return Arrays.copyOf(tempAnswer, idx);
    }
}
