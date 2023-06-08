class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid[0].size();
        for (auto& row : grid){

            int index = upper_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin();
            count += (n - index);
        }
        return count;
    }
};
