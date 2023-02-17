class Solution {
public:
    double myPow(double x, int n) {
        
        double res = 1 ;
        long nn = n;
        if(nn<0) nn*=-1;
        
        while(nn>0){
            if(nn%2 == 1){
                res = res * x;
                nn = nn-1;
            }else{
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0){
            res = 1/res;
        }
        return res;
    }
    
};