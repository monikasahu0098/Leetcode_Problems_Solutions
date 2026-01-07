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
    long long SUM = 0;
    long long maxP = 0;
    const int MOD = 1e9 + 7;

    long long totalSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        long long leftSubtreeSum = totalSum(root->left);
        long long rightSubtreeSum = totalSum(root->right);

        long long subtreeSum = root->val + leftSubtreeSum + rightSubtreeSum;

        // only calculate product AFTER SUM is known
        if (SUM != 0) {
            long long remainingSubtreeSum = SUM - subtreeSum;
            maxP = max(maxP, subtreeSum * remainingSubtreeSum);
        }

        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {
        maxP = 0;

        SUM = totalSum(root);   // 1st pass → get total sum
        totalSum(root);         // 2nd pass → calculate product

        return maxP % MOD;
    }
};
