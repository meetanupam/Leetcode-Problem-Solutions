class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, iStar = -1, jStar = -1;
        while (i < m) 
        {
            if (j < n && (s[i] == p[j] || p[j] == '?')) 
            {
                i++;
                j++;
            } else if (j < n && p[j] == '*') 
            {
                iStar = i;
                jStar = j;
                j++;
            } else if (iStar >= 0) 
            {
                i = ++iStar;
                j = jStar + 1;
            } else 
            {
                return false;
            }
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};
