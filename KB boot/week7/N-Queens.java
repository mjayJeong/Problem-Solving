class Solution {
    int answer = 0;
    int[] queens;
    
    public int solution(int n) {
        queens = new int[n];
        backtrack(0, n);
        return answer;
    }
    
    public void backtrack(int row, int n) {
        if (row == n) {
            answer++;
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isValid(row, col)) {
                queens[row] = col;
                backtrack(row + 1, n);
            }
        }
    }
    
    public boolean isValid(int row, int col) {
        for (int prevRow = 0; prevRow < row; prevRow++) {
            int prevCol = queens[prevRow];
            
            if (prevCol == col) return false;
            
            if (Math.abs(prevCol - col) == Math.abs(prevRow - row)) return false;
        }
        return true;
    }
}
