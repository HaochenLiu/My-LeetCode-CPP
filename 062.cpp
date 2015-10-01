/*
062. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Above is a 3 x 7 grid. How many possible unique paths are there?
Note: m and n will be at most 100.
*/

/*
DP
Time: O(nm)
Space: O(nm)
Extra space: O(nm)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > f(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            f[i][0] = 1;
        }
            
        for(int j = 0; j < n; j++) {
            f[0][j] = 1;
        }
            
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
                
        return f[m-1][n-1];
    }
};
