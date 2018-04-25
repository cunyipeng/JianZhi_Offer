class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        set<int> save;
        set<int>::iterator iter;
        for (int i = 0; i < data.size(); i++){
            if (save.find(data[i]) == save.end())
                save.insert(data[i]);
            else{
                iter = save.find(data[i]);
                save.erase(iter);
            }
        }
        iter = save.begin();
        *num1 = *iter;
        *num2 = *(++iter);
    }
};
