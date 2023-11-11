class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0 && t.size() == 0) return true;
        int x = 0;
        int n = s.size();
        for (char c: t)
        {
            if (c == s[x])
            {
                x++;
            }
            if (x == n)
            {
                return true;
            }
        }
        return false;
    }
};