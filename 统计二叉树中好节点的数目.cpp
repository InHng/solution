class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int mx) {
        if (root == NULL) {
            return;
        }
        if (root->val >= mx) {
            ++ans;
            mx = root->val;
        }
        dfs(root->left, mx);
        dfs(root->right, mx);
    }
    
    int goodNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        dfs(root, root->val);
        return ans;
    }
};
