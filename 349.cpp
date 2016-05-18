/*
349. Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> map;
        vector<int> result;

        for(int i=0;i<nums1.size();i++)
        {
            map[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++)
        {
            if(map[nums2[i]] > 0)
            {
                result.push_back(nums2[i]);
                map[nums2[i]] = 0;
            }
        }

        return result;

    }
};
