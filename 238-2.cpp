/*
238. Product of Array Except Self

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).
For example, given [1,2,3,4], return [24,12,8,6].
Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;

        vector<int> res(n, 0);
        int numOfZero = 0;
        int zeroIdx = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                numOfZero++;
                zeroIdx = i;
                if(numOfZero > 1) {
                    return res;
                }
            }
        }
        
        if(numOfZero == 0) {
            res[0] = 1;
            for(int i = 1; i < n; i++) {
                res[0] *= nums[i];
            }
            
            for(int i = 1; i < n; i++) {
                res[i] = res[i - 1] / nums[i];
                res[i] *= nums[i - 1];
            }
        } else {
            res[zeroIdx] = 1;
            for(int i = 0; i < n; i++) {
                if(i == zeroIdx) {
                    continue;
                }
                res[zeroIdx] *= nums[i];
            }
        }
        return res;
    }
};
