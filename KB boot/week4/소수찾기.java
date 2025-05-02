import java.util.*; 

class Solution {
    Set<Integer> numberSet = new HashSet<>();
    
    public int solution(String numbers) {
        boolean visited[] = new boolean[numbers.length()];
        backtrack("", numbers, visited);
        
        int count = 0;
        for (int num : numberSet) {
            if (isPrime(num)) count++;
        }
        return count;
    }
    
    public void backtrack(String current, String numbers, boolean[] visited) {
        if (!current.equals("")) {
            numberSet.add(Integer.parseInt(current));
        }
        
        for (int i = 0; i < numbers.length(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                backtrack(current + numbers.charAt(i) , numbers, visited);
                visited[i] = false;
            }
        }
    }
    
    public boolean isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false; 
        }
        return true;
    }
}
