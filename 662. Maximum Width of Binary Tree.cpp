class Solution {
    typedef unsigned long long ULL;
    vector<vector<ULL>> v;
    ULL ans = 0;
    void dfs(TreeNode *node, int lv, ULL nodeId) {
        if (!node) return;
        if (v.size() <= lv) v.push_back({ULLONG_MAX, 0});
        v[lv][0] = min(v[lv][0], nodeId);
        v[lv][1] = max(v[lv][1], nodeId);
        ans = max(ans, v[lv][1] - v[lv][0] + 1);
        dfs(node->left, lv + 1, 2 * nodeId);
        dfs(node->right, lv + 1, 2 * nodeId + 1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0, 0);
        return ans;
    }
};
