class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int> last(256, -1);      // last index of each char
    int l = 0, maxLen = 0;

    for (int r = 0; r < s.size(); r++) {
        if (last[s[r]] >= l) l = last[s[r]] + 1;   // jump past the previous occurrence
        last[s[r]] = r;
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}
};