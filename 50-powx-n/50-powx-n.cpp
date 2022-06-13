// hint : https://cp-algorithms.com/algebra/binary-exp.html
class Solution {
public:
    /*BRUTE FORCE APPROACH 
    double myPow(double x, int n) {
     if(n==0){
         return 1;
     }
        long double ans;
        if(n<0) ans = myPow(1/x,0-n);
        else ans=x*myPow(x,n-1);
        return ans;
    }
    */
    double myPow(double x, int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        double ans=1.0;
        long long nn = n;
        if(nn < 0) nn=-1*nn;
        while(nn){
            if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            else if(nn%2!=0){
                ans = x*(ans);
                nn=nn-1;
            }
        }
        if(n<0){
            ans = (double)(1.0)/(double)(ans);  // type casting here is important
        }
        return ans;
    }
};