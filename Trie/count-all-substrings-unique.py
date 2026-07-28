class TrieNode:
    def __init__(self):
        self.child = {}

class Solution:
    def countSubs(self, s):
        # code here
        root = TrieNode()
        nodes = 0
        for i in range(len(s)):
            curr = root
            for j in range(i,len(s)):
                char = s[j]
                if char not in curr.child:
                    curr.child[char] = TrieNode()
                    nodes += 1
                curr = curr.child[char]
        return nodes
        