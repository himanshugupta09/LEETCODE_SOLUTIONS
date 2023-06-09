class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      
      int l = 0,r = letters.size()-1,mid;

      while(l <= r)
      {
          mid = (l+r)/2;

          if(letters[mid] <= target)
          {
              l = mid+1;
          }
          else
          {
              r = mid-1;
          }
      }

      return l == letters.size() ? letters[0] : letters[l];
    }
};
