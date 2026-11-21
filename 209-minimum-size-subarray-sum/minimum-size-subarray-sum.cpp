class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int len=1e9;
        int i=0;

        int currSum=0;
        for(int j=0;j<n;j++){
            currSum += nums[j];

            while(currSum>=target){
                len=min(len,j-i+1);
                currSum-=nums[i];
                i++;
            }
        }
        return (len==1e9)? 0 : len;

    }
};