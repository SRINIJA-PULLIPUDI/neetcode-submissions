/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxi = -10000;
    int maxPath(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        maxi = max(maxi,(left+right+root->val));
        maxi = max(maxi,root->val);
        maxi = max(maxi,max(left,right)+root->val);
        return max(root->val, max(left,right)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        int res = maxPath(root);
        return maxi;
    }
};
