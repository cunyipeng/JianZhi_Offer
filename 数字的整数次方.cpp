class Solution {
public:
    double Power(double base, int exponent) {
        long long r = abs((long long)exponent);
        double a = 1.0;
        while(r){
            if(r & 1) a*=base;
            base*=base;
            r = r>>1;
        }
        return exponent < 0 ? 1/ a : a;
    }
};
