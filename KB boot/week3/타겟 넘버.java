class Solution {
    int answer = 0;
    public int solution(int[] numbers, int target) {
        get_target(numbers, target, 0, 0);
        return answer;
    }
    
    private void get_target(int numbers[], int target, int sum, int index) {
        if (index == numbers.length) {
            if (sum == target) {
                answer++;
            }
            return;
        }
        get_target(numbers, target, sum + numbers[index], index+1);
        get_target(numbers, target, sum - numbers[index], index+1);
    }
}
