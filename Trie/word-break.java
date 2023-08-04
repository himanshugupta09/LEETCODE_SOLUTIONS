class TrieNode {
    TrieNode[] children;
    boolean endOfWord;

    TrieNode() {
        children = new TrieNode[26];
        for (int i = 0; i < 26; i++) {
            children[i] = null;
        }
        endOfWord = false;
    }

    void insert(TrieNode root, String str) {
        TrieNode curr = root;

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            int idx = c - 'a';

            if (curr.children[idx] == null) {
                curr.children[idx] = new TrieNode();
            }
            curr = curr.children[idx];
        }
        curr.endOfWord = true;
    }

    boolean search(TrieNode root, String str) {
        TrieNode curr = root;

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            int idx = c - 'a';

            if (curr.children[idx] == null) {
                return false;
            }
            curr = curr.children[idx];
        }
        return curr != null && curr.endOfWord;
    }
}

class Solution {
    Boolean[] memo;

    public boolean wordBreakUtil(String A, TrieNode root, int start) {
        if (start == A.length()) {
            return true;
        }
        if (memo[start] != null) {
            return memo[start];
        }

        for (int i = start + 1; i <= A.length(); i++) {
            if (root.search(root, A.substring(start, i)) && wordBreakUtil(A, root, i)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        TrieNode root = new TrieNode();
        for (String word : wordDict) {
            root.insert(root, word);
        }

        memo = new Boolean[s.length()];
        return wordBreakUtil(s, root, 0);
    }
}
