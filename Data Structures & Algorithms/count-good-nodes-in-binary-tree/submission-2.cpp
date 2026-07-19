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
int res=0;
    void good(TreeNode* root, int maxi){
        if(!root) return;
        if(root->val >= maxi){
            res++;
            maxi = root->val;
        }
        good(root->left, maxi);
        good(root->right, maxi);
    }
    int goodNodes(TreeNode* root) {
        int x=-101;
        good(root, x);
        return res;
    }
};  
