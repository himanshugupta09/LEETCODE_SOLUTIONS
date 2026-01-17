class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        key_mapper = {}
        for string in strs:
            strstd = ''.join(sorted(string))
            if strstd in key_mapper:
                key_mapper[strstd].append(string)
            else:
                key_mapper[strstd] = [string]
        return list(key_mapper.values())