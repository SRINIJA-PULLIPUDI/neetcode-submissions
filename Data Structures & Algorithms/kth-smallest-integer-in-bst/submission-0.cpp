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
int l = 0;
    void kth(TreeNode* root, int& k){
        if(!root){
            return;
        }
        kth(root->left, k);
        k-=1;
        if(k==0) {
            l = root->val;
            return;
        }
        kth(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        kth(root, k);
        return l;
    }
};
