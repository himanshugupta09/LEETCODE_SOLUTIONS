from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque()
        res = []
        if not root:
            return res
        q.append(root)

        while q:
            temp = []
            n = len(q)
            for _ in range(n):
                front = q.popleft()
                temp.append(front.val)
                if front.left:
                    q.append(front.left)
                if front.right:
                    q.append(front.right)
            res.append(temp)
            #print(q)
        return res[::-1]
            
        