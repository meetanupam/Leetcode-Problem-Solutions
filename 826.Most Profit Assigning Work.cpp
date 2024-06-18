class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;
        vector<pair<int, int>> jobs;
        for(int i = 0; i < difficulty.size(); i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for(int i = 0, j = 0, maxProfit = 0; i < worker.size(); i++) {
            while(j < jobs.size() && jobs[j].first <= worker[i]) {
                maxProfit = max(maxProfit, jobs[j].second);
                j++;
            }
            ans += maxProfit;
        }
        return ans;
    }
};
