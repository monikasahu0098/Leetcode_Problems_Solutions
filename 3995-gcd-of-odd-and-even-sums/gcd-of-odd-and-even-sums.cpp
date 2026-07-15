class Solution {
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int sumEven=0;
        int num1=1;
        int num2=2;
        
        for(int i=1;i<=n;i++){
            sumOdd+=num1;
            num1+=2;
        }
        for(int j=1;j<=n;j++){
            sumEven+=num2;
            num2+=2;
        }

        return gcd(sumOdd, sumEven);
    }
};