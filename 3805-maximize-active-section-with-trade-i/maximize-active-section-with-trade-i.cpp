class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> zeroGroups;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                zeroGroups.push_back(j - i);
                i = j;
            } else {
                i++;
            }
        }

        int bestMerge = 0;
        for (int k = 0; k + 1 < (int)zeroGroups.size(); k++) {
            bestMerge = max(bestMerge, zeroGroups[k] + zeroGroups[k + 1]);
        }

        int ones = count(s.begin(), s.end(), '1');
        return ones + bestMerge;
    }
};