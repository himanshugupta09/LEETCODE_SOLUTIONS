'''
#Mathematical approach 
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        
        i = j = 0
        
        while i < len(version1) or j < len(version2):
            v1 = v2 = 0
            
            while i < len(version1) and version1[i] != '.':
                v1 = v1*10 + int(version1[i])
                i += 1
            while j < len(version2) and version2[j] != '.':
                v2 = v2*10 + int(version2[j])
                j += 1
            if v1 > v2:
                return 1
            elif v2 > v1:
                return -1
            i,j = i+1,j+1
        return 0
        
'''

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        lv1 = version1.split('.')
        lv2 = version2.split('.')
        ln = max(len(lv1),len(lv2))
        """
        This is two pointer approach
        """
        
        for i in range(ln):
            v1 = int(lv1[i]) if i < len(lv1) else 0
            v2 = int(lv2[i]) if i < len(lv2) else 0
            if v1 < v2:
                return -1
            if v1 > v2:
                return 1
        return 0
            
