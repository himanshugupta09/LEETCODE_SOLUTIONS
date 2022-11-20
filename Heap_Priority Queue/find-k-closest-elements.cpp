/* APPROACH 1 --> USING MAX. HEAP 

1. store all the elements of the array in a heap as pair as heap[i] = {arr[i]-x,arr[i]}
2. Store Till size of the heap is less than k.
3. As the size becomes k, start poping out elements till size_of_heap > 0.
4. Finally Return the left elements of the heap.


Time Complexity : O(NlogN)
Sapce Complexity : O(K) 

*/



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
         priority_queue<pair<int,int>>max_heap;
        
        
        
        for(int i=0;i<arr.size();i++)
        {
            max_heap.push({abs(arr[i]-x),arr[i]});
            if(max_heap.size()>k)
            {
                max_heap.pop();
                
            }
            
        }
        
        vector<int>res;
        
        while(!max_heap.empty())
        {
            
            res.push_back(max_heap.top().second);
            max_heap.pop();
            
            
        }
        sort(res.begin(),res.end());
        
        
        return res;
        
    }
};


//=========================================================================================================================================================================
//                                                   APPROACH 2 -> TWO POINTERS
//=========================================================================================================================================================================
/* APPROACH 2 --> USING TWO POINTERS 

1. Set two pointers as i,j where i will point to start and j will point to end of array.
2. Now check if differnce of arr[i]-x >arr[j]-x then increment i to 1 else decrement j to -1.
3.  Now create a empty list that will store our final result
4. In this list store elemnts from the array from i pointer last position to j pointer last position




Time Complexity : O(N)
Sapce Complexity : O(1) 

*/



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
       vector<int>res;
        
        int i=0,j = arr.size()-1;
        
        while(j-i >= k)
        {
           if(abs(arr[i]-x) > abs(arr[j] - x))
           {
               i++;
           }
            else{
                j--;
            }
            
        }
        for (int s = i; s <= j; s++) res.push_back(arr[s]);
        
        return res;
    }
};
