class Solution:
    def solve(self,string,str_list,n):
        if len(string) == n:
            str_list.append(string)
            return
        for i in "abc":
            if string[-1] != i:
                string += i
                self.solve(string,str_list,n)
                string = string[0:len(string)-1]
                #self.solve(string,str_list,n)
        
        
    def getHappyString(self, n: int, k: int) -> str:
        if n == 1 and k > 3:
            return ""
        elif n == 1 and k <= 3:
            if k == 1:
                return "a"
            elif k == 2:
                return "b"
            else:
                return "c"
        else:
            str_list = []
            for i in "abc":
                string = i
                self.solve(string,str_list,n)
            str_list.sort()
            #print(str_list)
            return str_list[k-1] if len(str_list) > k-1 else ""