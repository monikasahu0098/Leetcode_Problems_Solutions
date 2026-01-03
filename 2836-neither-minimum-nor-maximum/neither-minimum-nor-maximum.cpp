class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int largest=INT_MIN;
        int sec_largest=INT_MIN;

        for(int n:nums){
            if(n>largest){
                sec_largest=largest;
                largest=n;
            }else if(n>sec_largest && n != largest){
                sec_largest=n;
            }
        } 
        if(sec_largest>INT_MIN && nums.size()>2){
            return sec_largest;
        }else{
            return -1;
        }
    }
};