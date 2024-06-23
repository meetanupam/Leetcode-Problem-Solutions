class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow = grid.size(), maxRow = -1;
        int minCol = grid[0].size(), maxCol = -1;
        
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                if (grid[r][c] == 1) {
                    if (r < minRow) minRow = r;
                    if (r > maxRow) maxRow = r;
                    if (c < minCol) minCol = c;
                    if (c > maxCol) maxCol = c;
                }
            }
        }
        
        int ht = maxRow - minRow + 1;
        int wh = maxCol - minCol + 1;
        
        return ht * wh;
    }
};
