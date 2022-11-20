class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        dic = {}
        for i in nums:
            if i not in dic:
                dic[i] = 1
            else:
                dic[i] += 1
                
        key_list = list(dic.keys())
        val_list = list(dic.values())
        position = val_list.index(max(val_list))
        
        return (key_list[position])
        
        
