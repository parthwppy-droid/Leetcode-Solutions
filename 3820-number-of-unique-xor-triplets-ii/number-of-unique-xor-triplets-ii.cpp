class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> S1(nums.begin(), nums.end());
        unordered_set<int> S2;
        for (int a : S1)
            for (int b : S1)
                S2.insert(a ^ b);

        unordered_set<int> ans;
        for (int c : S2)
            for (int x : S1)
                ans.insert(c ^ x);

        return ans.size();
    }
};