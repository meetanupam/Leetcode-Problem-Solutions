class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        while (--n) 
        {
            stringstream next;
            for(int i=0; i<ans.length(); ++i) 
            {
                int count = 1;
                while(i+1<ans.length() && ans[i] == ans[i + 1]) 
                {
                    ++count;
                    ++i;
                }
                next << count << ans[i];
            }
            ans = next.str();
        }

        return ans;
    }
};
