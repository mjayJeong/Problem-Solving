class Solution {
    public String solution(String new_id) {
        String answer = "";
        answer = new_id.toLowerCase();
        answer = answer.replaceAll("[^a-z0-9-_.]", "");
        answer = answer.replaceAll("\\.{2,}", ".");
        answer = answer.replaceAll("^[.]|[.]$", "");
        
        if (answer.length() == 0) {
            answer = answer.concat("a");
        }
        
        if (answer.length() >= 16) {
            answer = answer.substring(0, 15);
            if (answer.endsWith(".")) {
                answer = answer.substring(0, answer.length() - 1);
            }
        }
        
        while (answer.length() <= 2) {
            answer = answer.concat(String.valueOf(answer.charAt(answer.length() - 1)));
        }
        
        return answer;
    }
}
