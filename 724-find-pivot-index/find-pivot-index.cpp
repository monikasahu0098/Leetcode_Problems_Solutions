class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            int leftSum=0;
            int rightSum=0;
            if(i==0){
                rightSum=prefix[n-1]-prefix[0];
            }else{
                leftSum=prefix[i-1];
                rightSum=prefix[n-1]-prefix[i];
            }
            if(leftSum==rightSum){
                return i;
            }
        }
        return -1;
    }
};