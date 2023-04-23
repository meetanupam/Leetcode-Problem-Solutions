int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (count(begin(nums), end(nums), 1) >0 ){
            return n - count(begin(nums), end(nums), 1);
        }
        int result = -1;
        for (int i = 0; i < n; ++i) {
            int current_gcd = nums[i];
            for (int j = i; j < n; ++j) {
                current_gcd = gcd(current_gcd, nums[j]);
                if (current_gcd == 1) {
                    result = (result == -1) ? (j - i) : std::min(result, j - i);
                    break;
                }
            }
        }
        return (result == -1) ? -1 : result + n - 1;
    }
};
