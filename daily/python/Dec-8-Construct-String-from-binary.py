class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        res = []
        self.dfs(root, res)
        return ''.join(res)

    def dfs(self, root: Optional[TreeNode], res: str):
        if root is None:
            return

        res.append(str(root.val))

        if root.left is not None or root.right is not None:
            res.append('(')
            self.dfs(root.left, res)
            res.append(')')

            if root.right is not None:
                res.append('(')
                self.dfs(root.right, res)
                res.append(')')
