class Solution:
    def goodNodes(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(node, mx):
            if node is None:
                return
            if node.val >= mx:
                nonlocal ans
                ans += 1
                mx = node.val
            dfs(node.left, mx)
            dfs(node.right, mx)

        dfs(root, root.val)
        return ans
