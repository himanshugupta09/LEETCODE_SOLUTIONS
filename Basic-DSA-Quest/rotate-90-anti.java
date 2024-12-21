//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int matrix[][] = new int[n][n];
            // String st[] = read.readLine().trim().split("\\s+");
            int k = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) matrix[i][j] = sc.nextInt();
            }
            Solution ob = new Solution();
            ob.rotateby90(matrix);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) System.out.print(matrix[i][j] + " ");
                System.out.println();
            }
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to rotate matrix anticlockwise by 90 degrees.
    static void rotateby90(int mat[][]) {
        // code here
        int  n = mat.length;
        //int m = mat[0].length;
        //int[][] rev = new int[n][m];
        
        
         for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                int temp = mat[i][j];
                
                mat[i][j] = mat[j][n-1-i];
                mat[j][n-1-i] = mat[n-1-i][n-1-j];
                mat[n-1-i][n-1-j] = mat[n-1-j][i];
                mat[n-1-j][i]=temp;
                
            }
        }
        
        
    }
}
