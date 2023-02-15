189. Rotate Array
//Approach: Using Reverse
//Runtime: 8 ms, faster than 88.24% of C++ online submissions for Rotate Array.
//Memory Usage: 10.1 MB, less than 37.73% of C++ online submissions for Rotate Array.
//time: O(N), space: O(1)
_______________________________________________________________________________________

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
