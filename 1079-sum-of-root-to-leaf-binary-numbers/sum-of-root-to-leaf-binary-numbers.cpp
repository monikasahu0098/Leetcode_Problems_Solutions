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
    int solve(TreeNode* root,int v){
        if(root==NULL){
            return 0;
        }
        v=(v*2)+root->val;

        if(root->left== NULL && root->right==NULL){
            return v;
        }
        return (solve(root->left,v)+solve(root->right,v));
    }
    int sumRootToLeaf(TreeNode* root) {
        return solve(root,0);
    }
};