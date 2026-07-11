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
    bool same(TreeNode* root, TreeNode* subRoot){
        if(root and !subRoot) return false;
        if(subRoot and !root) return false;
        if(subRoot and root and root->val!=subRoot->val) return false;
        if(!subRoot and !root) return true;
        bool left = same(root->left, subRoot->left);
        bool right = same(root->right, subRoot->right);
        return (left and right);
    }
    void sub(TreeNode* root, TreeNode* subRoot, bool& res){
        if(!root) return;
        if(same(root,subRoot)) {
            res = true;
            return;
        }
        sub(root->left, subRoot, res);
        if(res==true) return;
        sub(root->right, subRoot, res);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool res = false;
        sub(root,subRoot,res);
        return res;
    }
};
