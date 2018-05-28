class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for(int i = 0; i < 32; i++)
        {
            int bits = 0;
            for(int j = 0; j < n; j++)
            {
                bits += (A[j] >> i) & 1;
            }
            result |= (bits % 3) << i;
        }
        return result;
    }
};
