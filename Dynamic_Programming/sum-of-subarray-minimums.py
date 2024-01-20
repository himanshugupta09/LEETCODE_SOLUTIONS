'''

Calculating Left Counts:

Iterates through the array from left to right:
For each element arr[i]:
Pops elements from stk1 until the top element is smaller than arr[i], maintaining a count of popped elements in cnt.
Appends [arr[i], cnt] to stk1.
Stores cnt in left[i], representing the count of elements to the left of arr[i] that are greater than or equal to it.
c. Calculating Right Counts:

Iterates through the array from right to left (using range(n-1, -1, -1))
Similar logic to the left count calculation, but using stk2 and storing counts in right.
d. Calculating the Sum:

Initializes res to 0.
Iterates through the array:
For each element arr[i]:
Calculates arr[i] * left[i] * right[i], representing the contribution of subarrays with arr[i] as the minimum element.
Adds this value to res and applies modulo mod to prevent overflow.
Returns the final res value, applying modulo mod again for consistency.

'''

mod = 10**9+7
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)
        right = [0]*n
        left = [0]*n
        stk1 = []
        stk2 = []
        for i in range(n):
            cnt = 1
            while stk1 and stk1[-1][0] > arr[i]:
                cnt += stk1[-1][1]
                stk1.pop()
            stk1.append([arr[i],cnt])
            left[i] = cnt
        for i in range(n-1,-1,-1):
            cnt = 1
            while stk2 and stk2[-1][0] >= arr[i]:
                cnt += stk2[-1][1]
                stk2.pop()
            stk2.append([arr[i],cnt])
            right[i] = cnt
        res = 0
        
        for i in range(n):
            res += (arr[i]*left[i]*right[i])
            res %= mod
        return res%mod
