class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        backtrack(nums, current, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<int>& current,
                   vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            bool alreadyUsed = false;
            for (int j = 0; j < current.size(); j++) {
                if (current[j] == nums[i]) {
                    alreadyUsed = true;
                    break;
                }
            }
            if (alreadyUsed)
                continue;

            current.push_back(nums[i]);
            backtrack(nums, current, result);
            current.pop_back();
        }
    }
};