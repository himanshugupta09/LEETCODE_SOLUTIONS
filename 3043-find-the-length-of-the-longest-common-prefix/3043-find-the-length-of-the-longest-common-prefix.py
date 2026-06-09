class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        arr1 = [str(i) for i in arr1]
        arr2 = [str(i) for i in arr2]

        hash1 = set()

        for i in range(len(arr1)):
            for j in range(1, len(arr1[i]) + 1):
                hash1.add(arr1[i][:j])

        max_len = 0

        for i in range(len(arr2)):
            for j in range(1, len(arr2[i]) + 1):
                prefix = arr2[i][:j]
                if prefix in hash1:
                    max_len = max(max_len, len(prefix))

        return max_len