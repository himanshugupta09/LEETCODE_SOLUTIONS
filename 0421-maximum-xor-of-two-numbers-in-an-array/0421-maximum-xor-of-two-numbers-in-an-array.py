class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        # Optimization 1: Find max bit depth to avoid useless leading zeroes
        max_num = max(nums)
        if max_num == 0: 
            return 0
        
        # .bit_length() gets the exact number of bits needed for the max number
        L = max_num.bit_length() 
        
        # Optimization 2: Nested dictionaries instead of TrieNode objects
        root = {}
        for num in nums:
            curr = root
            for i in range(L - 1, -1, -1):
                bit = (num >> i) & 1
                if bit not in curr:
                    curr[bit] = {}
                curr = curr[bit]
                
        max_xor = 0
        for num in nums:
            curr = root
            curr_xor = 0
            for i in range(L - 1, -1, -1):
                bit = (num >> i) & 1
                oppos_bit = 1 - bit
                
                curr_xor <<= 1
                if oppos_bit in curr:
                    curr = curr[oppos_bit]
                    curr_xor |= 1
                else:
                    curr = curr[bit]
                    # Note: curr_xor |= 0 is mathematically useless, so we can omit it!
                    
            max_xor = max(max_xor, curr_xor)
            
        return max_xor