# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque([])
        res = []
        if not root:
            return res
        q.append(root)

        while q:
            temp = []
            n = len(q)
            for i in range(n):
                front = q.popleft()
                temp.append(front.val)
                if front.left:
                    q.append(front.left)
                if front.right:
                    q.append(front.right)
            res.append(temp)
            #print(q)
        return res
            
        