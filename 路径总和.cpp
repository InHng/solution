class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        targetSum -= root->val;
        if (root->left == root->right) {
            return targetSum == 0;
        }
        return hasPathSum(root->left, targetSum) or hasPathSum(root->right, targetSum);
    }
};
