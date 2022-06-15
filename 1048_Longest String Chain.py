class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        memo = {}
        words_set = set(words)

        def get_next_word(word, index):
            return word[:index] + word[index + 1:]

        def dfs(word):
            if word in memo:
                return memo[word]

            total_length = 1
            for i in range(len(word)):
                next_word = get_next_word(word, i)
                if next_word in words_set:
                    current_length = 1 + dfs(next_word)
                    total_length = max(total_length, current_length)
            memo[word] = total_length
            return total_length

        ans = 0
        for word in words_set:
            ans = max(ans, dfs(word))
        return ans