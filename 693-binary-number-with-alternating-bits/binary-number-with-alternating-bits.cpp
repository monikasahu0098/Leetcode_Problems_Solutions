class Solution {
public:
    // bool hasAlternatingBits(int n) {
    //     unsigned int result=n^(n>>1);
    //     return (result&(result+1))==0;
    // }
    bool hasAlternatingBits(int n){
        int countBit=n%2;
        n=n/2;
        while(n>0){
            if(countBit==n%2){
                return false;
            }
            countBit=n%2;
            n=n/2;
        }
        return true;
    }
};