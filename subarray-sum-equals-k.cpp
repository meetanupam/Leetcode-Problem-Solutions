class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // map to store frequency of sums
        int count = 0; // variable to store the count of subarrays with sum k
        int Sum = 0; // variable to store the sum at each index
        
        freq[0] = 1; // initialize frequency of sum 0 as 1
        
        for (int i = 0; i < nums.size(); i++) 
        {
            Sum = Sum+nums[i]; // calculate sum at current index
            
            if (freq.find(Sum - k) != freq.end()) 
            {
                count = count+freq[Sum - k]; // increment count by frequency of (sum - k)
            }
            
            freq[Sum]++; // increment frequency of current sum
        }
        
        return count; // return the count of subarrays with sum k
    }
};
