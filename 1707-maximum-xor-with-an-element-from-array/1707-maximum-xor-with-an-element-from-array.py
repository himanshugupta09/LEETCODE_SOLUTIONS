class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        nums.sort()
        offline_query = sorted([(m,x,i) for i,(x,m) in enumerate(queries)])

        res = [-1]*len(queries)
        root = {}
        num_idx = 0
        n = len(nums)

        for m,x, org_idx in offline_query:
            while num_idx < n and nums[num_idx] <= m:
                curr = root
                for i in range(31,-1,-1):
                    bit = (nums[num_idx] >> i) & 1
                    if bit not in curr:
                        curr[bit] = {}
                    curr = curr[bit]
                num_idx += 1
            if not root:
                continue
            curr_root = root
            max_xor = 0
            for i in range(31,-1,-1):
                bit = (x >> i) & 1
                tog = 1 - bit
                if tog in curr_root:
                    max_xor |= (1 << i)
                    curr_root = curr_root[tog]
                else:
                    curr_root = curr_root[bit]
            res[org_idx] = max_xor
        return res 



