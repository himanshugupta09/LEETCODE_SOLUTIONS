class Solution {
public:
    void mergesort(int s,int e,vector<int>& indices,vector<pair<int,int>>& original,vector<pair<int,int>>& sorted){
        if(s>=e) return;
        int m=s+(e-s)/2;
        mergesort(s,m,indices,original,sorted);
        mergesort(m+1,e,indices,original,sorted);
        int i=s;
        int l=s,r=m+1;
        
        int lessinright=0;
        while(l<=m and r<=e){
            if(original[l]<original[r]){
                indices[original[l].second]+=lessinright;
                sorted[i++]=original[l++];
            }else if(original[l]>original[r]){
                sorted[i++]=original[r++];
                lessinright++;
            }else{
                l++;
                r++;
            }
        }
        while(l<=m){
            indices[original[l].second]+=lessinright;
            sorted[i++]=original[l++];
        }
        while(r<=e){
            sorted[i++]=original[r++];
        }
        for(int k=s;k<=e;k++){
            original[k]=sorted[k];
        }
    }
    vector<int> countSmaller(vector<int>& arr) {
        int n=arr.size();
        vector<int>indices(n,0);
        vector<pair<int,int>>original;
        vector<pair<int,int>>sorted;
        for(int i=0;i<n;i++){
            original.push_back({arr[i],i});
            sorted.push_back({arr[i],i});
        }
        mergesort(0,n-1,indices,original,sorted);
        return indices;
    }
};
