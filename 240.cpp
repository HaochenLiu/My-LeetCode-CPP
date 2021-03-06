/*
240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]


Given target = 5, return true.
Given target = 20, return false.
*/

/*
Time: O(n+m)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int i = 0;
        int j = matrix[0].size() - 1;
        
        while (i < matrix.size() && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            } else if (target < matrix[i][j]) {
                j--;
            } else {
                i++;
            }
        }
        
        return false;
    }
};
