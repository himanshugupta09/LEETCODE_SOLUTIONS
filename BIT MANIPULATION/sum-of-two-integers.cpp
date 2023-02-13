class Solution {
public:
    int getSum(int a, int b) {
      
      while(b != 0)
      {
          unsigned cary = a&b;
            a = a^b;
            b = cary << 1;

      }
      return a;

    }
};
