/*
107. Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

   3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
Time: O(n)
Space: O(n)
Extra space: O(w)
w is the width of the tree. 
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        vector<int> record;
        queue<TreeNode*> q;
        TreeNode* node;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            node = q.front();
            q.pop();
            if(node == NULL) {
                res.push_back(record);
                record.clear();
                if(!q.empty()) {
                    q.push(NULL);
                } else {
                    break;
                }
            } else {
                record.push_back(node->val);
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
