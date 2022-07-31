class NumArray:

    def __init__(self, nums: List[int]):
        self.sqrt = int(len(nums)**(0.5))
        self.sumarr = [0]*(len(nums)//self.sqrt+(len(nums)%self.sqrt!=0)*1)
        self.nums = nums
        for i in range(len(nums)):
            self.sumarr[i//self.sqrt]+=nums[i]
        
        
    def update(self, index: int, val: int) -> None:
        oldv = self.nums[index]
        self.nums[index] = val
        self.sumarr[index//self.sqrt] += val - oldv 

    def sumRange(self, left: int, right: int) -> int:
        lidx = left//self.sqrt
        ridx = right//self.sqrt
        tsum = 0
        
        for i in range(lidx+1,ridx): # Overlapping blocks
            tsum+=self.sumarr[i]
            
        for i in range(left,min(right+1,((lidx+1)*self.sqrt))): # first block
            tsum+=self.nums[i]
                       
        if ridx!=lidx: # last block
            for i in range(ridx*self.sqrt,right+1):
                tsum+=self.nums[i]
        return tsum


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
