class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i <= n; i++)
        {
            int sum = 0;
            int nm = i;


            while(nm != 0)
            {
                sum += nm%2;
                nm = nm/2;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
