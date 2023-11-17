class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return (self.Height(root) >= 0)
    
    def Height(self, root):
        if root is None: return 0
        leftH, rightH = self.Height(root.left), self.Height(root.right)
        if leftH < 0 or rightH < 0 or abs(leftH - rightH > 1): return -1
        return max(leftH, rightH) + 1