class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        n = len(nums)
        temp = set()
        for i in range(n-1):
            j = i+1
            k = n-1
            while j  < k:
                if (nums[i]+nums[j]+nums[k]) == 0:
                    temp.add((nums[i],nums[j],nums[k]))
                    j += 1
                    k -= 1
                elif nums[i]+nums[j]+nums[k] > 0:
                    k -= 1
                else:
                    j += 1
        return list(list(i) for i in temp)


        