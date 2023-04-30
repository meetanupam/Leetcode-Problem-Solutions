class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> arr(n);
        
        for (int i=0; i<n; i++) 
        {
            arr[i] = make_pair(heights[i], names[i]);
        }
        
        sort(arr.rbegin(), arr.rend()); // sort in descending order
        
        vector<string> res(n);
        for (int i=0; i<n; i++) 
        {
            res[i] = arr[i].second;
        }
        
        return res;
    }
};
