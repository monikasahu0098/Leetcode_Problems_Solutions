class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixSum(n);

        prefixSum[0]=nums[0];

        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            int l=0;
            int r=0;
            if(i==0){
                r=prefixSum[n-1]-prefixSum[i];
            }else{
                l=prefixSum[i-1];
                r=prefixSum[n-1]-prefixSum[i];
            }
            if(l==r){
                return i;
            }
        }
        return -1;
    }
};