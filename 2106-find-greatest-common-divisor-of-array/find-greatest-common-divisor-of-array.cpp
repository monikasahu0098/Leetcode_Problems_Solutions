class Solution {
public:
    int GCD(int a,int b){
        if(b==0){
            return a;
        }
        return GCD(b ,a%b);
    }
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        return GCD(maxi,mini);
    }
};