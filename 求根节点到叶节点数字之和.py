class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(node, x):
            if node is None:
                return
            x = x * 10 + node.val
            if node.left is None and node.right is None:
                nonlocal ans
                ans += x
                return
            if node.left:
                dfs(node.left, x)
            if node.right:
                dfs(node.right, x)

        dfs(root, 0)
        return ans
