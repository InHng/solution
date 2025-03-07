class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int sum) {
        if (root == NULL) {
            return;
        }
        sum = sum * 10 + root->val;
        if (root->left == NULL and root->right == NULL) {
            ans += sum;
            return;
        }
        if (root->left != NULL) {
            dfs(root->left, sum);
        }
        if (root->right != NULL) {
            dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        dfs(root, 0);
        return ans;
    }
};
