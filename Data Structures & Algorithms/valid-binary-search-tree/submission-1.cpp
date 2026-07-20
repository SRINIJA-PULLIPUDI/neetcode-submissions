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
    bool res=true;
    pair<int,int> valid(TreeNode* root){
        if(root->left==nullptr and root->right==nullptr){
            return {root->val, root->val};
        }
        pair<int,int> l = {INT_MAX, INT_MIN};
        pair<int,int> r = {INT_MAX, INT_MIN};
        if(root->left)  l = valid(root->left);
        if(root->right)  r = valid(root->right);
        if(res!=false){
            if(l.second>=root->val or r.first<=root->val){
                res = false;
            }
        }
        return {min({l.first, root->val}), max({root->val, r.second})};
    }
    bool isValidBST(TreeNode* root) {
        pair<int,int> k = valid(root);
        return res;
    }
};
