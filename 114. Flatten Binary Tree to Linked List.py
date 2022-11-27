# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root == None:
            return root
        else:
            stk = [root]
            while stk:
                node = stk.pop()
                if node.right:
                    stk.append(node.right)
                if node.left:
                    stk.append(node.left)
                node.left = None
                node.right = stk[-1] if stk else None
        return node         
