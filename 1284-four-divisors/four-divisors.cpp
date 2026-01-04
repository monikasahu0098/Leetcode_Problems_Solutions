class Solution {
public:
    int findSumDivisors(int &num){
        int divisor=0;
        int sum=0;

        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                int other=num/i;
                if(other==i){
                    divisor+=1;
                    sum+=(i);
                }else{
                    divisor+=2;
                    sum+=(i+other);
                }
            }
            if(divisor>4) return 0;
        }
        return divisor==4? sum:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int result=0;
        for(int &num:nums){
            result+=findSumDivisors(num);
        }
        return result;
    }
};