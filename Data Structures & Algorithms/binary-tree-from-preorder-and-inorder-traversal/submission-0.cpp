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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 or inorder.size()==0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int mid;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==root->val){
                mid = i;
                break;
            }
        }
        vector<int> l(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> r(inorder.begin(), inorder.begin()+mid);
        root->left = buildTree(l,r);
        vector<int> m(preorder.begin()+1+mid, preorder.end());
        vector<int> n(inorder.begin()+mid+1, inorder.end());
        root->right = buildTree(m,n);
        return root;
    }
};