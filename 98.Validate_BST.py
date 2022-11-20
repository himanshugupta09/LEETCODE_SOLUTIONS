# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        res = self.verify(root,-float('inf'),float('inf'))
        
        return res
        
    def verify(self,root,lb,rb):
        
        if root is None:
            return True
        
        if not(root.val > lb and root.val < rb):
            return False
        
        
        right = self.verify(root.right,root.val,rb)
        left = self.verify(root.left,lb,root.val)
        
        return right and left
    
