class Solution {
    public int[] twoSum(int[] nums, int target) {
        int left = 0;
        int right = 1;

        while (left < nums.length - 1) {
            if (nums[left] + nums[right] == target) {
                return new int[] {left, right};
            }
            right++;

            if (right >= nums.length) {
                left++;
                right = left + 1;
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
