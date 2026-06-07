# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes = {}
        child = set()
        for par,node,isLeft in descriptions:
            if par not in nodes:
                nodes[par] = TreeNode(par)
            if node not in nodes:
                nodes[node] = TreeNode(node)
            if isLeft:
                nodes[par].left = nodes[node]
            else:
                nodes[par].right = nodes[node]
            child.add(node)
        for par,_,_ in descriptions:
            if par not in child:
                return nodes[par]

        
