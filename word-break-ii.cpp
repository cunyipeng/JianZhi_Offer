class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> *dp = new vector<bool>[s.size()];
        for (int i = 0;i < s.size();i++) {
            for (int j = 0;j < s.size() - i;j++) {
                if (dict.find(s.substr(i, j + 1)) != dict.end())
                    dp[i].push_back(true);
                else
                    dp[i].push_back(false);
            }
        }
        vector<string> result; vector<string> words;
        output(s.size() - 1, s, result, words, dp);
        return result;
    }
 
    void output(int x, string s, vector<string> &result, vector<string> &words, vector<bool> *dp) {
        if (x == -1) {
            string sentence;
            for (int i = words.size() - 1;i >= 0;i--) {
                sentence+=words[i];
                if (i != 0) sentence += " ";
            }
            result.push_back(sentence);
        } else {
            for (int i = x;i >= 0;i--) { 
                if (dp[i][x - i]) {
                    words.push_back(s.substr(i, x - i + 1));
                    output(i - 1, s, result, words, dp);
                    words.pop_back();
                }
            }
        }
    }
};
