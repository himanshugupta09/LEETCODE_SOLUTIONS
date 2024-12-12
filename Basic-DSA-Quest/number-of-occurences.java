//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());

        while (tc-- > 0) {

            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                a[i] = Integer.parseInt(str[i]);
            }
            String[] nk = br.readLine().trim().split(" ");
            int k = Integer.parseInt(nk[0]);
            Solution sln = new Solution();
            int ans = sln.countFreq(a, k);

            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    int countFreq(int[] arr, int target) {
        // code here
       int l  = 0;
       int n =  arr.length;
       int h = n-1;
       
         int count = 0;
    
    while (l <= h) {
        int mid = l + (h - l) / 2;
        
        if (arr[mid] == target) {
            // Count the occurrences of `x` on the left side
            int left = mid - 1;
            while (left >= l && arr[left] == target) {
                count++;
                left--;
            }
            
            // Count the occurrences of `x` on the right side
            int right = mid + 1;
            while (right <= h && arr[right] == target) {
                count++;
                right++;
            }
            
            // Include the middle element itself
            count++;
            
            // Now return the total count
            break;
        }
        else if (arr[mid] > target) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    
    return count;
    }
}
