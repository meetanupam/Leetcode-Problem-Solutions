class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n =nums.size();
        vector<int> ok(value);
        for(int i=0;i<n;i++){
            nums[i] = (nums[i] % value + value)%value;
            ok[nums[i]]++;
        }
        int ans=0;
        for(int now=0;;now=(now+1)%value){
            if(!ok[now]) return ans;
            ok[now]--;
            ans++;
        }
        return 0;
    }
};
