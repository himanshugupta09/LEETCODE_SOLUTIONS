class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n = len(s)
        if n < k:
            return False
        
        total = 1 << k
        seen = [False] * total
        mask = total - 1
        hash_val = 0
        count = 0
        
        for i in range(n):
            hash_val = ((hash_val << 1) & mask) | int(s[i])
            
            if i >= k - 1 and not seen[hash_val]:
                seen[hash_val] = True
                count += 1
                if count == total:
                    return True
        
        return False