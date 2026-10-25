class Solution {
public:
    double myPow(double x, int n) {
        double ans;
        if(n==-1){
            return 1/x;
        }
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        else{
            if(n>0){
                double to = myPow(x,n/2);
                if(n%2==0){
                    ans= to * to;
                }
                else{
                    ans = x * to * to;
                }                
            }
            else{
                double ne;
                long long N = n;
                N = -N;
                double to = myPow(x,N/2);
                if(N%2==0){
                    ne = to * to;
                }
                else{
                    ne = x * to * to;
                }
                ans = 1 / ne;
            }
        }
        return ans;
    }
};