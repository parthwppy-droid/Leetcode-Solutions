class Solution {
public:
   int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; i++) P[i + 1] = P[i] + nums[i];

    deque<int> dq;
    int ans = INT_MAX;

    for (int j = 0; j <= n; j++) {
        while (!dq.empty() && P[j] - P[dq.front()] >= k) {
            ans = min(ans, j - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && P[j] <= P[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(j);
    }
    return ans == INT_MAX ? -1 : ans;
}
};