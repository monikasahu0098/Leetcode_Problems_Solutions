class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;

        int sign=(dividend<0)^(divisor<0) ? -1:1;
        long long ldividend=labs(dividend);
        long long ldivisor=labs(divisor);

        int quotient=0;
        while(ldividend>=ldivisor){
            long long temp=ldivisor;
            int multiple=1;
            while(ldividend>=(temp<<1)){
                temp<<=1;
                multiple<<=1;
            }
            quotient+=multiple;
            ldividend-=temp;
        }
        return sign*quotient;
    
    }
};