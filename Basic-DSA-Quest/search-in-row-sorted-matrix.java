//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class gfg {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            int mat[][] = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) mat[i][j] = sc.nextInt();
            }

            int x = sc.nextInt();

            if (new Solution().matSearch(mat, x))
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    // public static boolean binarySearch(int a[],int x,int m)
    // {
    //     int low = 0,high = m-1;
    //     while(low <= high)
    //     {
    //         int mid = (low+high)/2;
    //         if(a[mid] == x)
    //         {
    //             return true;
    //         }
    //         else if(a[mid] > x)
    //         {
    //             high = mid-1;
    //         }
    //         else
    //         {
    //             low = mid+1;
    //         }
    //     }
    //     return false;
    // }
    public static boolean matSearch(int mat[][], int x) {
        // your code here
        int n =  mat.length;
        int m = mat[0].length;
        int i = 0, j = m - 1;
    
    while (i < n && j >= 0) {
        if (mat[i][j] == x) {
            return true; // Found the element
        } else if (mat[i][j] > x) {
            j--; // Move left
        } else {
            i++; // Move down
        }
    }
    
    return false;
    }
}
