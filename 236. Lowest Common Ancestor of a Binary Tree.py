# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


''' 
Firstly start trversing from the rott->left if any of p or q is found return to its             parent node and from the parent node start 
            traversing to the right if you find any               
            of node at right (p or q) return to its parent
            else return Null to its parent 
            
            Finally at the end  return the node from the nodes under which you got the p & q
             Its a recursion Approch.
             '''

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Base Case
        if (root == None or root == p or root == q):
            return root
        left = self.lowestCommonAncestor(root.left,p,q) # Call for the Left Sub-Tree
        right = self.lowestCommonAncestor(root.right,p,q) # Call for the Right Sub-Tree
        
        # Result
        if left == None:
            return right
        elif right == None:
            return left
        else:
            return root

'''
Time Complexity : O(N)
Space Complexity : O(N) for the auxialry stack space in worst case
'''        
        
