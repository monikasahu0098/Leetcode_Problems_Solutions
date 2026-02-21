class Solution {
public:
    bool isPrime(int num){
        if(num<=1){
            return false;
        }
        bool flag=true;
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                flag=false;
                break;
            }
        }
        if(flag){
            return true;
        }else{
            return false;
        }
    }
    bool count(int n){
        string binary="";
        while(n>0){
            int rem=n%2;
            binary=to_string(rem)+binary;
            n=n/2;
        }
        int count=0;
        for(char &c:binary){
            if(c=='1'){
                count++;
            }
        }
        if(isPrime(count)){
            return true;
        }
        return false;    
    }
    int countPrimeSetBits(int left, int right) {
        int result=0;
        for(int i=left;i<=right;i++){
            if(count(i)){
                result++;
            }
        }
        return result;
    }
};