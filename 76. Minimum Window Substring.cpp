class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charCount;
        for (char c : t) {
            charCount[c]++;
        }
        
        int left = 0, right = 0, count = t.size(), minLen = INT_MAX, minStart = 0;
        while (right < s.size()) {
            if (charCount[s[right]]-- > 0) {
                count--;
            }
            right++;
            
            while (count == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }
                
                if (charCount[s[left++]]++ == 0) {
                    count++;
                }
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
