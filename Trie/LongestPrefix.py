class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Solution:
    def longestString(self, words):
        if not words:
            return ""
            
        root = TrieNode()
        
        # 1. Build the Trie
        for word in words:
            curr = root
            for char in word:
                if char not in curr.children:
                    curr.children[char] = TrieNode()
                curr = curr.children[char]
            curr.is_end = True
            
        # 2. DFS to find the longest valid path
        longest_word = ""
        
        def dfs(node, current_word):
            nonlocal longest_word
            
            # Check if this valid word is the longest we've seen, 
            # or the lexicographically smallest if there's a tie in length.
            if len(current_word) > len(longest_word):
                longest_word = current_word
            elif len(current_word) == len(longest_word) and current_word < longest_word:
                longest_word = current_word
                
            # Explore all children
            for char, child_node in node.children.items():
                # CORE LOGIC: We ONLY continue down paths where the prefix exists as a full word
                if child_node.is_end:
                    dfs(child_node, current_word + char)
                    
        # Start the DFS from the root with an empty string
        dfs(root, "")
        
        return longest_word