class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, maxi = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        for (int i = 0; i < s.size(); i++) {
            if (vowels.count(s[i])) {
                maxi++;
            }
            if (i >= k && vowels.count(s[i - k])) {
                maxi--;
            }
            ans = max(ans, maxi);
        }
        
        return ans;
    }
};
