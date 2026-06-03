class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        initial_start = -1
        initial_end = -1
        res = []
        print(intervals)
        for i in range(len(intervals)):
            if initial_start == -1 and initial_end == -1:
                initial_start = intervals[i][0]
                initial_end = intervals[i][1]
            else:
                if intervals[i][0] <= initial_end:
                
                    initial_end = max(initial_end,intervals[i][1])
                else:
                    res.append([initial_start,initial_end])
                    initial_start = intervals[i][0]
                    initial_end = intervals[i][1]
        res.append([initial_start,initial_end])
        return res