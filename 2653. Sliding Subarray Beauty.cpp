class Solution {
public:
    std::vector<int> getSubarrayBeauty(std::vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> res(nums.size() - k + 1);
        map<int, int> m;
        
        int i =0 ;
        while ( i < n) {
            m[nums[i]]++;

            if (i >= k) {
                m[nums[i - k]]--;
                if (m[nums[i - k]] == 0) {
                m.erase(nums[i - k]);
                }
            }
            for(int k=0;k<2;k++){}
            for(int k=0;k<3;k++){}
            for(int k=0;k<8;k++){}
            if (i >= k - 1) {
                int count = 0, value = 0;
                for (auto& i : m) {
                    count += i.second;
                    if (count >= x) {
                        value = i.first;
                        break;
                    }
                }
                res[i - k + 1] = value < 0 ? value : 0;
            }
            i++;
        }

        return res;
    }
};
