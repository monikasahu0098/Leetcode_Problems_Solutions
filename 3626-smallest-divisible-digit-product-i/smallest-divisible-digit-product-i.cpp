class Solution {
public:
    int productOfD(int n){
        int pro=1;
        while(n>0){
            int rem=n%10;
            pro*=rem;
            n=n/10;
        }
        return pro;
    }
    int smallestNumber(int n, int t) {
        for(int x=n;x<200;x++){
            if(productOfD(x)%t==0){
                return x;
            }
        }
        return -1;
    }
};