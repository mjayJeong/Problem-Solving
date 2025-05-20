import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            String rotated = s.substring(i) + s.substring(0, i); 
            if (isValid(rotated)) {
                answer++;
            }
        }

        return answer;
    }

    private boolean isValid(String str) {
        Stack<Character> stack = new Stack<>();

        for (char ch : str.toCharArray()) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            } else {
                if (stack.isEmpty()) return false;
                char top = stack.pop();
                if (!isMatching(top, ch)) return false;
            }
        }

        return stack.isEmpty();
    }

    private boolean isMatching(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }
}
