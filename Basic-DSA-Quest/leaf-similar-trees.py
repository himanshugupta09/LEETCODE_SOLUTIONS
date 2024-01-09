# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        lvs1 = []
        lvs2 = []
        def get_leaves(root,ls):
            if not(root.left) and not(root.right):
                ls.append(root.val)
                return
            elif not(root.left) and root.right:
                get_leaves(root.right,ls)
            elif not(root.right) and root.left:
                get_leaves(root.left,ls)
            else:
                get_leaves(root.left,ls)
                get_leaves(root.right,ls)
        get_leaves(root1,lvs1)
        get_leaves(root2,lvs2)
        return lvs1 == lvs2
    
            
