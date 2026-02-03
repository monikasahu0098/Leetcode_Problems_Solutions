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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int>result;
        while(curr != NULL){
            if(curr->left == NULL){
                result.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* IP=curr->left;
                while(IP->right != NULL && IP->right != curr){
                    IP=IP->right;
                }

                if(IP->right == NULL){
                    IP->right=curr;
                    curr=curr->left;
                }else{
                    IP->right=NULL;
                    result.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return result;
    }
};