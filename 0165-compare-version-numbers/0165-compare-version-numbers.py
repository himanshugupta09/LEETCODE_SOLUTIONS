class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        n = max(len(v1),len(v2))
        for i in range(n):
            a = int(v1[i]) if i < len(v1) else 0
            b = int(v2[i]) if i < len(v2) else 0

            if a > b:
                return 1
            elif a < b:
                return -1

        return 0