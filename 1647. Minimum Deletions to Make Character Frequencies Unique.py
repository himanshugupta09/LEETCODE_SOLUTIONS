class Solution:
    def minDeletions(self, s: str) -> int:
        has=  {}
        for i in s:
            if i in has:
                has[i]+=1
            else:
                has[i] = 1
        v = list(has.values())
        v.sort(reverse =  True)
        del_char = 0
        mx_allow = len(s)
        for i in v:
            if i>mx_allow:
                del_char+=+i-mx_allow
                i = mx_allow
            mx_allow = max(0,i-1)
        return del_char          