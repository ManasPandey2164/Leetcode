class Solution {
public:
    double myPow(double x, long long n) {
        double ans;
        if(n==0){
            return 1;
        }
        double to = myPow(x,n/2);
        if(n<0) return 1/myPow(x,-1*n);
        if(n%2==0){
            ans= to * to;
        }
        else{
            ans = x * to * to;
        }                
        return ans;
    }
};