class Solution {
public:
    int integerBreak(int n) {
        if(n<=3){
            return (n-1);
        }
        int product=1;
        while(n>4){
            product=product*3;
            n=n-3;
        }
        return product*n;
    }
};