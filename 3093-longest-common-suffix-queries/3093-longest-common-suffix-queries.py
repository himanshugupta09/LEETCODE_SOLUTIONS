class TrieNode:
    def __init__(self):
        self.child = {}
        self.min_len = float("inf")
        self.idx = float("inf")
class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self,s:str,idx:int):
        node = self.root
        if len(s) < node.min_len:
            node.min_len = len(s)
            node.idx = idx
        for ch in s:
            c = ch
            if c not in node.child:
                node.child[c] = TrieNode()
            node = node.child[c]

            if len(s) < node.min_len:
                node.min_len = len(s)
                node.idx = idx
    def query(self,s:str) -> int:
        node = self.root
        for ch in s:
            if ch in node.child:
                node = node.child[ch]
            else:
                break
        return node.idx
    



class Solution:
    def stringIndices(self, wordsContainer: List[str], wordQuery: List[str]) -> List[int]:
        trie = Trie()

        for i,word in enumerate(wordsContainer):
            reverse_word = word[::-1]
            trie.insert(reverse_word,i)
        res = []
        for query in wordQuery:
            reversed_query = query[::-1]
            res.append(trie.query(reversed_query))
        return res    
        