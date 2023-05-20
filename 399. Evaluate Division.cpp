using PSD = pair<string, double>;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string, vector<PSD>> graph;
        unordered_set<string> nodes;
        unordered_set<string> visited;

        for (int i = 0 ; i < equations.size() ; ++i ) 
        {
            string from = equations[i][0];
            string to = equations[i][1];
            graph[from].push_back({to, values[i]});
            graph[to].push_back({from, 1 / values[i]});
            nodes.insert(from);
            nodes.insert(to);
        }

        for (auto node : nodes) {
            graph[node].push_back({node, 1});
        }

        function<void(string, string, double)> dfs = [&](string source, string target, double cur) {
            
            for (auto [to, cost] : graph[source]) {
                if (to == target) {
                    ans.back() = cur * cost;
                    return;
                }
                if (visited.count(to) == 0) {
                    visited.insert(to);
                    dfs(to, target, cur * cost);
                }
            }
        };
        
        for (auto querie : queries) {
            string source = querie[0];
            string target = querie[1];
            visited.clear();
            ans.push_back(-1);
            
            if (graph.count(source)) {
                if (source == target) {
                    ans.back() = 1;
                }else {
                    visited.insert(source);
                    dfs(source, target, 1);
                }
            }    
        }

        return ans;
    }
};v
