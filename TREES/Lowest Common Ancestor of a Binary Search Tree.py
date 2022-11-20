# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
"""
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

"""
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        # Firstly Check that root exist or not if does not exist return None
        
        if root is None:
            return None
        
        if root == p or root == q:
            return root
        
        # Now firstly go to left sub-tree and check for the LCA 
        # Here we will recursively call the LCA() function that at every node and find the ancestor
        
        left = self.lowestCommonAncestor(root.left,p,q) # call for the left sub- trer
        right  = self.lowestCommonAncestor(root.right,p,q) # Call for the right sub-Tree
        
        """
        Now we will apply the conditions to reach the result 
        if our right is None then we simply return the left value
        Similarly if our left is None then we will return the right value
        else in case of BST we are well aware that lowest value resides at left sub-tree 
        so we by default return left value if above fail to meet 
        
        """
        
        if left and right:
            return root
        
        if right is None:
            return left
        else:
            return right
        
        
"""

Time Complexity : O(N)
Space Complexity : O(1) Auxilary Stack Space 

"""        
