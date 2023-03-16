class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int i,j,m=accounts.size(),n=accounts[0].size(),maxw=0;
        for(i=0;i<m;i++)
        {
            int w=0;
            for(j=0;j<n;j++)
            {
                w+=accounts[i][j];
            }
            maxw=max(maxw,w);   
        }
        return maxw;
    }
};
