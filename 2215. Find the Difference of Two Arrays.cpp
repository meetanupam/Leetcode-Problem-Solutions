class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        vector<vector<int>> ans(2);

        for (int num : s1) {
            if (s2.find(num) == s2.end()) {
                ans[0].push_back(num);
            }
        }

        for (int num : s2) {
            if (s1.find(num) == s1.end()) {
                ans[1].push_back(num);
            }
        }

        return ans;
    }
};
