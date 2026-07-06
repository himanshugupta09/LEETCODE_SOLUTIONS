class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        rem = 0
        intervals.sort(key = lambda x: (x[0],-x[1]))
        end = 0
        for start,ends in intervals:
            if end < ends:
                end = ends
                rem += 1
        return rem