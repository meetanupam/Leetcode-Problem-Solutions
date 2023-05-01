class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int sum = 0, minSal = INT_MAX, maxSal = INT_MIN;
        
        for (int i=0; i<n; i++) 
        {
            sum += salary[i];
            minSal = min(minSal, salary[i]);
            maxSal = max(maxSal, salary[i]);
        }
        
        return (double)(sum - minSal - maxSal) / (n - 2);
    }
};
