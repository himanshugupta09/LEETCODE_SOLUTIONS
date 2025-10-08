class TrieNode:
    """Represents a node in the Trie data structure."""
  
    def __init__(self):
        # Array to store references to child nodes (26 letters a-z)
        self.children = [None] * 26
        # Flag to mark if this node represents the end of a word
        self.is_end_of_word = False


class WordDictionary:
    """
    Data structure that supports adding words and searching with wildcard '.' support.
    Uses a Trie (prefix tree) for efficient storage and retrieval.
    """
  
    def __init__(self):
        """Initialize the WordDictionary with an empty Trie."""
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        """
        Add a word to the dictionary.
      
        Args:
            word: The word to be added (contains only lowercase letters)
        """
        current_node = self.root
      
        # Traverse through each character in the word
        for char in word:
            # Calculate the index for this character (0-25 for a-z)
            index = ord(char) - ord('a')
          
            # Create a new node if path doesn't exist
            if current_node.children[index] is None:
                current_node.children[index] = TrieNode()
          
            # Move to the child node
            current_node = current_node.children[index]
      
        # Mark the end of the word
        current_node.is_end_of_word = True

    def search(self, word: str) -> bool:
        """
        Search for a word in the dictionary.
        Supports '.' as a wildcard that can match any single character.
      
        Args:
            word: The word pattern to search for
          
        Returns:
            True if the word exists in the dictionary, False otherwise
        """
      
        def dfs_search(word_substring: str, node: TrieNode) -> bool:
            """
            Helper function to recursively search with wildcard support.
          
            Args:
                word_substring: Remaining part of the word to search
                node: Current node in the Trie
              
            Returns:
                True if pattern matches, False otherwise
            """
            # Process each character in the remaining word
            for i in range(len(word_substring)):
                char = word_substring[i]
              
                if char == '.':
                    # Wildcard: try all possible children
                    for child_node in node.children:
                        if child_node is not None:
                            # Recursively search with remaining substring
                            if dfs_search(word_substring[i + 1:], child_node):
                                return True
                    # No valid path found through any child
                    return False
                else:
                    # Regular character: check if path exists
                    index = ord(char) - ord('a')
                    if node.children[index] is None:
                        return False
                    # Move to the next node
                    node = node.children[index]
          
            # Check if we've reached a valid word ending
            return node.is_end_of_word
      
        # Start search from the root
        return dfs_search(word, self.root)