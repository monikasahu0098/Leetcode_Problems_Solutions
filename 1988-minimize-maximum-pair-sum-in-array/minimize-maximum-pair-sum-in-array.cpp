class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans=0;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            ans=max(ans,sum);
            i++;
            j--;
        }
        return ans;
    }
};