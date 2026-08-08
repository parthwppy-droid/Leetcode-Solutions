class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int num : nums) diff ^= num;   

        int bit = diff & (-(unsigned int)diff);            

        int x = 0, y = 0;
        for (int num : nums) {
            if (num & bit) x ^= num;
            else y ^= num;
        }
        return {x, y};
    }
};
