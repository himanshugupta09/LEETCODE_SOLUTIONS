//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t > 0) {
            int rows = sc.nextInt();
            int columns = sc.nextInt();

            int matrix[][] = new int[rows][columns];

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    matrix[i][j] = sc.nextInt();
                }
            }
            int target = sc.nextInt();

            Solution x = new Solution();

            if (x.searchRowMatrix(matrix, target))
                System.out.println("true");
            else
                System.out.println("false");
            t--;

            System.out.println("~");
        }
    }
}
// } Driver Code Ends




class Solution {
    // Function to search a given number in row-column sorted matrix.
    public boolean  binarySearch(int []a,int m,int x)
    {
        int low = 0,high = m-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(a[mid] == x)
            {
                return true;
            }
            else if(a[mid] > x)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return false;
    }
    public boolean searchRowMatrix(int[][] mat, int x) {
        // code here
        int n = mat.length;
        int m = mat[0].length;
        int j = m-1;
        for(int i=0;i<n;i++)
        {
            if(mat[i][j] >= x)
            {
                boolean ok = binarySearch(mat[i],m,x);
                if(ok){
                    return true;
                }
            }
        }
        return false;
    }
}
