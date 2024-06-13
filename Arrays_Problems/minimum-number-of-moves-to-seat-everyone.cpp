/*
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int res = 0;
        int n = seats.size();
        for(int i=0;i<n;i++)
        {
            res += abs(seats[i]-students[i]);
        }
        return res;
    }
};

Approach with sorting 
*/

class Solution {
public:
    // Approach using Couting Sort
    
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int sm = *max_element(seats.begin(),seats.end());
        int stm = *max_element(students.begin(),students.end());
        int maxi = max(sm,stm);
        
        vector<int>bucks(maxi,0);
        
        for(int pos:seats)
        {
            bucks[pos-1]++;
        }
        for(int pos:students)
        {
            bucks[pos-1]--;
        }
        int res = 0;
        int un = 0;
        
        for(int d:bucks)
        {
            res += abs(un);
            un += d;
        }
        return res;
    }
};
