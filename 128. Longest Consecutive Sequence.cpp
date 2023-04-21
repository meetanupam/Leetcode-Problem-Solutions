class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.empty())
        return 0;

        int max = 0, count = 1;
        for(int i=1;i<nums.size();i++)
        {
          if(nums[i]-1==nums[i-1])
          {
            count ++;
          }
          else if(nums[i]==nums[i-1])
          {
            continue;
          }
          else
          {
            max = std::max(max, count);
            count = 1;
          }
        }
        return std::max(max, count);
    }
};

