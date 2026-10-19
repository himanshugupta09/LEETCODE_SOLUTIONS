class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        nums.sort()
        l = 0
        r = len(nums)-1
        if nums[l] == nums[r] and nums[l] == target:
            return list(i for i in range(len(nums)))
        res_set = set()
        while l <= r:
            mid = l + (r-l)//2
            if nums[mid] < target:
                l = mid+1
            elif nums[mid] > target:
                r = mid-1
            else:
                res_set.add(mid)
                if mid + 1 < len(nums) and nums[mid + 1] == target:
                    res_set.add(mid + 1)
                if mid + 2 < len(nums) and nums[mid + 2] == target:
                    res_set.add(mid + 2)
                if mid - 1 > 0 and nums[mid - 1] == target:
                    res_set.add(mid - 1)
                r = mid - 1
        return sorted(list(res_set))

        