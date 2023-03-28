from os import *
from sys import *
from collections import *
from math import *

def paintCost(n, k, costs):
    
    # Write your code here
    # Return an integer denoting the answer
    for i in range(1,n):
        for j in range(0,k):
            mini = float('inf')
            for l in range(0,k):
                if l != j:
                    mini = min(mini,costs[i-1][l])
            costs[i][j] = costs[i][j]+mini

    return min(costs[n-1])                
