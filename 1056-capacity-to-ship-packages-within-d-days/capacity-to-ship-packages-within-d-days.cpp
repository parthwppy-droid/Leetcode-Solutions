class Solution {
public:
    bool isValid(int mid, vector<int>& weights, int days) {
        int days_need = 1;
        int current_sum = 0;
        for (int weight : weights) {
            if (current_sum + weight > mid) {
                days_need++;          // need a new painter/day
                current_sum = weight; // this load starts the new day
            } else {
                current_sum += weight;
            }
        }
        return days_need <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(
            weights.begin(),
            weights.end()); // can't go below the largest single item
        int high = accumulate(weights.begin(), weights.end(),
                              0); // worst case: everything in one day
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid, weights, days)) {
                answer = mid; // mid works — try to find an even smaller valid
                              // capacity
                high = mid - 1;
            } else {
                low = mid + 1; // mid too small — need more capacity
            }
        }
        return answer;
    }
};