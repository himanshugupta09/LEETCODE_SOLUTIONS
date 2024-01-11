# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def get_max(root,cur_max,cur_min):
            if not(root):
                return abs(cur_max-cur_min)
            cur_max = max(cur_max,root.val)
            cur_min  = min(root.val,cur_min)
            left_max = get_max(root.left,cur_max,cur_min)
            right_max = get_max(root.right,cur_max,cur_min)
            
            return max(left_max,right_max)
        return get_max(root,root.val,root.val)
