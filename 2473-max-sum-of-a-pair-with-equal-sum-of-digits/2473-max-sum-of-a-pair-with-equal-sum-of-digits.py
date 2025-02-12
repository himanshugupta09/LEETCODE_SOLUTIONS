from collections import defaultdict
class Solution:
    def sum_of_digit(self,num):
        res = 0
        while num != 0:
            res += (num%10)
            num //= 10
        return res

    def maximumSum(self, nums: List[int]) -> int:
        nums.sort()
        res = -1
        dig_map = defaultdict(list)
        for num in nums:
            dig_sum = self.sum_of_digit(num)
            if dig_sum in dig_map:
                dig_map[dig_sum].append(num)
            else:
                dig_map[dig_sum] = [num]
        #print(dig_map)
        for num_list in dig_map.values():
            if len(num_list) >= 2:
                local_sum = num_list[len(num_list)-1]+num_list[len(num_list)-2]
                res = max(res,local_sum)
        return res


        