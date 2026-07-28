class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()
        

    def addWord(self, word: str) -> None:
        curr = self.root
        for char in word:
            if char not in curr.children:
                curr.children[char] = TrieNode()
            curr = curr.children[char]
        curr.is_end = True
        
    def search(self, word: str) -> bool:
        
        def dfs(index, node):
            # 1. Base Case: We have looked at every letter in the word.
            # Are we standing on a node that marks the end of a valid word?
            if index == len(word):
                return node.is_end
            
            char = word[index]
            
            # 2. The Wildcard Branching
            if char == '.':
                # Check every single child of our current node
                for child_node in node.children.values():
                    # If ANY of these paths eventually return True, we found a match!
                    if dfs(index + 1, child_node):
                        return True
                # If we checked all children and none worked out, this path is a dead end
                return False
                
            # 3. Standard Letter Traversal
            else:
                if char not in node.children:
                    return False
                # Move to the next index, and step down into the specific child node
                return dfs(index + 1, node.children[char])
                
        # Start the search at the first letter (index 0) and the top of the Trie (root)
        return dfs(0, self.root)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)