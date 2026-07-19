class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixSum(n,0);
        prefixSum[0]=nums[0];

        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        for(int i=0;i<n;i++){
            int l,r;
            if(i==0){
                l=0;
                r=prefixSum[n-1]-prefixSum[i];
            }else if(i==n-1){
                l=prefixSum[i-1];
                r=0;
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