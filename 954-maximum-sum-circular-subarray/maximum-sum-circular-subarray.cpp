class Solution {
public:
    int kadaneMin(vector<int>&nums){
        int n=nums.size();
        int currSum=nums[0];
        int minSum=nums[0];

        for(int i=1;i<n;i++){
            currSum=min(nums[i],currSum+nums[i]);
            minSum=min(minSum,currSum);
        }
        return minSum;
    }
    int kadaneMax(vector<int>&nums){
        int n=nums.size();
        int currSum=nums[0];
        int maxSum=nums[0];

        for(int i=1;i<n;i++){
            currSum=max(nums[i],currSum+nums[i]);
            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        
        int minSum=kadaneMin(nums);
        int maxSum=kadaneMax(nums);
        
        int cirMaxSum=sum-minSum;

        if(maxSum>0){
            return max(maxSum,cirMaxSum);
        }
        return maxSum;
        
    }
};