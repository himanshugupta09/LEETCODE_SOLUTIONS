class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        ver1 = version1.split('.')
        ver2 = version2.split('.')
        if len(ver1) < len(ver2):
            while len(ver1) < len(ver2):
                ver1.append('0')
        if len(ver1) > len(ver2):
            while len(ver1) > len(ver2):
                ver2.append('0')
        for i in range(len(ver1)):
            if int(ver1[i]) < int(ver2[i]):
                return -1
            elif int(ver1[i]) > int(ver2[i]):
                return 1
        return 0