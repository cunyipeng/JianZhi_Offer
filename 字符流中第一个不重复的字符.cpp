class Solution
{
    queue<char> data;
    char cnt[128]; 
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        ++cnt[ch - '\0'];
        if(cnt[ch - '\0'] == 1)
            data.push(ch);
        
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!data.empty() && cnt[data.front() - '\0'] >= 2) data.pop();
        if(data.empty()) return '#';
        return data.front();
    }

};
