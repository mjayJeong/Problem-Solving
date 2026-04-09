class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> answer;

    void backtracking(int start, int depth, int n) {
        if (tmp.size() == depth) {
            answer.push_back(tmp);
            return;
        }

        for (int i = start; i <= n; i++) {
            tmp.push_back(i);
            backtracking(i + 1, depth, n);
            tmp.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(1, k, n);
        return answer;
    }
};
