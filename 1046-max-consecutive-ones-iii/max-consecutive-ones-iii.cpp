class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int l = 0, zeros = 0, maxLen = 0;

    for (int r = 0; r < nums.size() ; r++) {
    if (nums[r] == 0) zeros++;
    if (zeros > k) {                 // slide the window by one, don't shrink it
        if (nums[l] == 0) zeros--;
        l++;
    }
}
return nums.size() - l;                        // the final window size is the answer
}
};