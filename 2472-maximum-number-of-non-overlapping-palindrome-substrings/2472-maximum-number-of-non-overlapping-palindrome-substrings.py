class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        T = "^#" + "#".join(s) + "#$"
        n = len(T)
        P = [0] * n 
        
        center = 0
        right_boundary = 0
        
        max_len = 0
        best_center = 0
        
        for i in range(1, n - 1):
            mirror = 2 * center - i
            
            if i < right_boundary:
                P[i] = min(right_boundary - i, P[mirror])
                
            while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
                P[i] += 1
            if i + P[i] > right_boundary:
                center = i
                right_boundary = i + P[i]
                
            if P[i] > max_len:
                max_len = P[i]
                best_center = i
        count = 0
        last_idx = -1
        
        for i in range(0,len(s)):
            start_k = i - k + 1
            if start_k > last_idx:
                center_k = start_k + i + 2
                if P[center_k] >= k:
                    count += 1
                    last_idx = i
                    continue 
            
            start_k1 = i - (k + 1) + 1 
            if start_k1 > last_idx:
                center_k1 = start_k1 + i + 2
                if P[center_k1] >= k + 1:
                    count += 1
                    last_idx = i
        return count 
