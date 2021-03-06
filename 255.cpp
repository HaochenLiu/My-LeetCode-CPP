/*
255. Verify Preorder Sequence in Binary Search Tree

Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
You may assume each number in the sequence is unique.
Follow up:
Could you do it using only constant space complexity?
*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        int i = -1;
        for(int j = 0; j < preorder.size(); j++) {
            if(preorder[j] < low) {
                return false;
            }

            while(i >= 0 && preorder[i] < preorder[j]) {
                low = preorder[i];
                i--;
            }

            i++;
            preorder[i] = preorder[j];
        }
        return true;
    }
};
