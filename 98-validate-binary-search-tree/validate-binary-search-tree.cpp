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
    bool solve(TreeNode* root, TreeNode* minimum,TreeNode* maximum){
        if(root==NULL){
            return true;
        }
        if(minimum != NULL && root->val<=minimum->val){
            return false;
        }
        if(maximum != NULL && root->val >=maximum->val){
            return false;
        }

        return solve(root->left,minimum,root) && solve(root->right,root,maximum);
    }
    bool isValidBST(TreeNode* root) {
        bool result=solve(root,NULL,NULL);
        return result;
    }
};