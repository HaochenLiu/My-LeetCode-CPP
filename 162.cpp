/*
162. Find Peak Element

A peak element is an element that is greater than its neighbors.
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -∞.
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
click to show spoilers.
Note:
Your solution should be in logarithmic complexity.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if(n == 1) {
            return 0;
        }
        for(int i = 1; i < n; i++) {
            if(num[i] < num[i - 1]) {
                return i - 1;
            }
        }
        return n - 1;
    }
};
