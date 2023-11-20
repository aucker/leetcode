class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        res = self.recur(root)
        if res == 1e9:
            return 0
        else:
            return res

    def recur(self, curr: Optional[TreeNode]) -> int:
        if curr==None:
            return 1e9
        if curr.left==None and curr.right==None:
            return 1
        return 1 + min(self.recur(curr.left), self.recur(curr.right))
