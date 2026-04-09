class Solution {
public:
    vector<vector<int>> answer;
    vector<int> tmp;

    void backtracking(int start, vector<int>& nums) {
        // 지금 상태 자체가 하나의 부분집합
        answer.push_back(tmp);

        for (int i = start; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtracking(i + 1, nums);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(0, nums);
        return answer;
    }
};
