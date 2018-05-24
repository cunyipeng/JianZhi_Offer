class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int l = s.length();
        vector<bool> dp(l+1, false);
        dp[0] = true;
        for(int i = 0; i < l; i++)
            for(int j = i; dp[i] && j<l; j++)
                if(dict.find(s.substr(i, j - i + 1)) != dict.end())
                    dp[j+1] = true;
        return dp[l];
    }
};
