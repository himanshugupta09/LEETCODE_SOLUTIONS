class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        binary = list(bin(n))
        binary = binary[1:]
        for i in range(1,len(binary)):
            if binary[i-1] == binary[i]:
                return False
        return True
        