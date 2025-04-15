class Solution {
    public int solution(String s) {
        int num = 0; 
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == '(') {
                num++;
            } else {
                num--;
                if (num < 0) return -1; 
                cnt++; 
            }
        }
        return num == 0 ? cnt : -1;
    }
}
