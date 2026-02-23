class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        # hashed = {}
        # for nums in range(0,pow(2,k)):
        #     binary = bin(nums)[::-1]
        #     #print(binary)
        #     binary = binary[:k+1]
        #     binary =  binary[::-1].replace('b','')
        #     #print(binary)
        #     hashed[binary] = 0
        #print(hashed)
        hashed = set()
        for i in range(0,len(s)):
            substr = s[i:i+k]
            #print(substr)
            hashed.add(substr)
        for nums in range(0,pow(2,k)+1):
            binary = bin(nums)[::-1]
            #print(binary)
            binary = binary[:k+1]
            binary =  binary[::-1].replace('b','')
            #print(binary)
            if len(binary) == k and binary not in hashed:
                #print(binary)
                return False
        return True

        