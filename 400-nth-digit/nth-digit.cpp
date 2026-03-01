class Solution {
public:
    int findNthDigit(int n) {
        long long digitLength=1;
        long long count=9;
        long long start=1;

        while(n>digitLength*count){
            n=n-digitLength*count;
            digitLength++;
            count*=10;
            start*=10;
        }
        long long number=start+(n-1)/digitLength;
        long long numberIndex=(n-1)%digitLength;

        string result=to_string(number);
        return result[numberIndex]-'0';

    }
};