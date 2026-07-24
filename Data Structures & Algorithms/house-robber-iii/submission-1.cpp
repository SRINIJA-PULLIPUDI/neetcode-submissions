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
    unordered_map<TreeNode*,int> mp;
    int robb(TreeNode* root){
        if(!root) return 0;
        if(mp[root]) return mp[root];
        int a=0,b=0,c=0,d=0;
        if(root->left and root->left->left) a = robb(root->left->left);
        if(root->left and root->left->right) b = robb(root->left->right);
        if(root->right and root->right->left) c = robb(root->right->left);
        if(root->right and root->right->right) d = robb(root->right->right);
        int pick = a+b+c+d+root->val;
        int l=0,r=0;
        if(root->left) l = robb(root->left);
        if(root->right) r = robb(root->right);
        int unpick = l+r;
        return mp[root] = max(pick,unpick);
    }
    int rob(TreeNode* root) {
        int res = robb(root);
        return res;
    }
};