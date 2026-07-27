class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;        // start at top row
        int col = cols - 1; // start at rightmost column

        while (row < rows && col >= 0) {
            if (matrix[row][col] == target) {
                return true; // found it
            } else if (matrix[row][col] > target) {
                col--; // current element too big → eliminate this column
            } else {
                row++; // current element too small → eliminate this row
            }
        }
        return false;
    }
}
;