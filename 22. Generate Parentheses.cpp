class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        dfs(n, n, path, ans);
        return ans;
    }
    
private:
    void dfs(int left, int right, string& path, vector<string>& ans) {
        if (left == 0 && right == 0) 
        {
            ans.push_back(path);
            return;
        }
        
        if (left > 0) 
        {
            path.push_back('(');
            dfs(left - 1, right, path, ans);
            path.pop_back();
        }
        
        if (right > left) 
        {
            path.push_back(')');
            dfs(left, right - 1, path, ans);
            path.pop_back();
        }
    }
};
