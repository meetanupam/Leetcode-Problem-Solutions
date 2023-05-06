class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1000000007;
        vector<int> exponents(nums.size(), 1);
        // calculate all the possible expoenents you might need and save them beforehand
        for(int i = 1; i < exponents.size(); ++i) {
            exponents[i]  = (2 * exponents[i - 1]) % MOD;
        }
        
        // sort the array, helps with the two pointer approach
        // the order of the elements in the subsequence doesn't matter anyway
        // because we are only concerned about the max and min in each of the subseqwuences
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums.size() - 1, count = 0;
        
        while(left <= right) {
            if(nums[left] + nums[right] > target) {
                right--;
            }
            else {
                
                /*
                * If right - left > 0, the count doesnt consider the case where no element
                * gets selected (empty subsequences not allowed). So we fix one of the elements (the leftmost one)
                * NOTE: The number of subsequences that can be made by x numbers = 2^x
                * (we have two options for each number -> to include it or to leave it)
                * so number of ways to select or not select numbers from [left + 1] ~ [right] = 2 ^ (right - (left + 1) + 1)
                */
                count = (count + exponents[right - left] )% MOD;
                left++;
            }
        }
        return (int) count;
    }
};
