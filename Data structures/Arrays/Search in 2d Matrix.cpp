/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        int col = matrix[0].size();
        int lo = 0, hi = matrix.size()*matrix[0].size()-1;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            int r = mid/col;
            int c = mid%col;
            if(matrix[r][c] == target)
                return true;
            else if(matrix[r][c] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
    }
};