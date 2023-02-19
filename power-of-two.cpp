class Solution {
public:
    bool isPowerOfTwo(int n) {
        // First Run a Loop From 0 to 30 as per the maximum constraint value

        for(int i=0;i<=30;i++)
        {
          
          // Initialize variable ans to calculate the power using pow function.

          int ans = pow(2,i); 

          /* Check whether the ans is equals to n or not, If it is True 
          Return True else False */

          if(ans == n)
          {
            return true;
          }
        }
    return false;
    }
};
