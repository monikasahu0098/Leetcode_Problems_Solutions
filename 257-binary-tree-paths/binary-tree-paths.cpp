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
    void allPaths(TreeNode* &root,string path,vector<string>&result){
        if(root->left==NULL && root->right==NULL){
            result.push_back(path);
            return;
        }
        if(root->left != NULL){
            allPaths(root->left,path+"->"+to_string(root->left->val),result);
        }
        if(root->right != NULL){
            allPaths(root->right,path+"->"+to_string(root->right->val),result);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;

        if(root==NULL){
            return result;
        }
        string path=to_string(root->val);
        allPaths(root,path,result);
        return result;
    }
};