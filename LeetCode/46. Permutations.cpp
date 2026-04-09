class Solution {
public:
    vector<vector<int>> answer;
    vector<int> tmp;
    vector<bool> visited;

    void backtracking(vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            answer.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            visited[i] = true;
            tmp.push_back(nums[i]);

            backtracking(nums);

            tmp.pop_back();
            visited[i] = false;
        } 
    }

    vector<vector<int>> permute(vector<int>& nums) {
        visited.assign(nums.size(), false);
        backtracking(nums);
        return answer;
    }
};
