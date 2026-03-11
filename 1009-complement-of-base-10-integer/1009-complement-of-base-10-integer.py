class Solution:
    def bitwiseComplement(self, n: int) -> int:
        bin_l = len(bin(n)[2:])
        maske = pow(2,bin_l)-1
        return n^maske
        
        