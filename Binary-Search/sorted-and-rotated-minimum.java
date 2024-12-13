//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine());

        Solution ob = new Solution(); // Instantiate the Solution object once

        while (t-- > 0) {
            String line = scanner.nextLine();
            String[] elements = line.split(" ");
            int[] arr = new int[elements.length]; // Changed to int[]

            for (int i = 0; i < elements.length; i++) {
                arr[i] = Integer.parseInt(elements[i]);
            }

            System.out.println(ob.findMin(arr));
            System.out.println("~");
        }
        scanner.close();
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int findMin(int[] arr) {
        // complete the function here
        int left =  0;
        int right =  arr.length-1;
        if(arr[left] < arr[right])
        {
            return arr[left];
        }
        while(left < right)
        {
            int mid = (left+right)/2;
            if(mid >  0 && arr[mid]  < arr[mid-1])
            {
                return arr[mid];
            }
            if(arr[mid] >= arr[left] && arr[mid] > arr[right])
            {
                left =  mid+1;
            }
            else
            {
                right =  mid-1;
            }
        }
        return arr[left];
    }
}
