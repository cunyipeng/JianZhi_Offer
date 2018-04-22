class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.size() ==  0)
            return res;
        Permutation(res, str, 0);
        sort(res.begin(), res.end());
        return res;
    }
    
    void Permutation(vector<string> &res, string str, int begin){
        if(begin == str.size() - 1)
            res.push_back(str);
        for(int i = begin; i <= str.size() - 1; i++){
            if(i!=begin && str[i] == str[begin])
                continue;
            swap(str[i], str[begin]);
            Permutation(res, str, begin + 1);
            swap(str[i], str[begin]); 
        }
    }
};
