class Solution:
    def carPooling(self, trips: list[list[int]], capacity: int) -> bool:
        events  = []
        for pas,st,en in trips:
            events.append([st,pas])
            events.append([en,-pas])
        events.sort()
        curr = 0
        for _,pas in events:
            curr += pas
            if curr > capacity:
                return False
        return True