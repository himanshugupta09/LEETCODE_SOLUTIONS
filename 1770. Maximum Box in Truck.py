class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key = lambda x:x[1],reverse = True)
        mx_tot_units = 0
        for nb,upb in boxTypes:
            nb = min(truckSize,nb)
            mx_tot_units += nb*upb
            truckSize-=nb
        return mx_tot_units    

      
# This Problem is From The Leet Code Daily July Challange  Day 1
# This Problem Requires only Prerequisite as Knowledge of Array 
# This Problem Has to Appproaches Greedy and Another is DP Solution 
# Here i Had shared my Greedy Approach To Problem 
        
