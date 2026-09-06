class Solution {
public:
    double myPow(double x, int n) {

        if(n==0) return 1;

        double p = 1;

        if(n<0){
            for(int i=1; i<=abs(n); i++){
                p /= x;
            }
        }
        else{
            for(int i = 1; i<=n; i++){
                p*= x;
            }
        }

        

        return p;
    }
};
