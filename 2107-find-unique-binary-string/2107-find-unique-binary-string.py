class Solution:
    def solve(self,st,n,string,lst):
        if len(string) == n and string not in st:
            lst.append(string)
            return 
        elif len(string) == n and string in st:
            return
        string += "0"
        self.solve(st,n,string,lst)
        string = string[0:len(string)-1]
        string += "1"
        self.solve(st,n,string,lst)

    def findDifferentBinaryString(self, nums: List[str]) -> str:
        st = set(nums)
        n  = len(nums[0])
        string = ""
        lst = []
        self.solve(st,n,string,lst)
        #print(lst)
        return lst[0]


        