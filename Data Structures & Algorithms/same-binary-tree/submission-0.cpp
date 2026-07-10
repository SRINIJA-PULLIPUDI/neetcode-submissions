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
void same(TreeNode* p, TreeNode* q,bool& res){
    if(p and !q) {
        res = false;
        return;
    }if(q and !p){
        res = false;
        return;
    }
    if(!p and !q) return;
    if(p->val != q->val){
        res = false;
        return;
    }
    same(p->left, q->left, res);
    if(res == false) return;
    same(p->right, q->right, res);
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = true;
        same(p,q,res);
        return res;
    }
};
