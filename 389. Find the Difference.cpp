class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int j=0;

        for(int i=0;i<s.size();i++)
        {
          if(s[i]==t[j])
          j++;

          else break;
        }

        return t[j];
    }
};
