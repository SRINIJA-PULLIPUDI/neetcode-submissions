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
    TreeNode* remove(TreeNode* root, int target){
        if(root->left==nullptr and root->right==nullptr){
            if(root->val==target) return nullptr;
            return root;
        }
        TreeNode* l=nullptr, *r=nullptr;
        if(root->left) l = remove(root->left,target);
        if(root->right) r = remove(root->right, target);
        root->right = r;
        root->left = l;
        if(l==nullptr and r==nullptr){
            if(root->val==target) return nullptr;
        }
        return root;
    } 
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* res = remove(root,target);
        return res;
    }
};