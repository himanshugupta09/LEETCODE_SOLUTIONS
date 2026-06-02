class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        def solve(s1,d1,s2,d2):
            fin1 = inf
            for i in range(len(s1)):
                fin1 = min(fin1,s1[i]+d1[i])
            fin2 = inf
            for i in range(len(s2)):
                fin2 = min(fin2,max(s2[i],fin1)+d2[i])
            return fin2
        land_water = solve(landStartTime,landDuration,waterStartTime,waterDuration)
        water_land = solve(waterStartTime,waterDuration,landStartTime,landDuration)
        return min(land_water,water_land)
