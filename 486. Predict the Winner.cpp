class Solution {
public:
    int score(vector<int>& nums, int si, int ei)
    {
        if(si == ei) return  nums[si];
        int chooseStart = nums[si] - score(nums, si+1, ei);
        int chooseEnd = nums[ei] - score(nums, si, ei - 1);

        return max(chooseStart, chooseEnd);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return score(nums, 0, n-1) >= 0;
    }
};
