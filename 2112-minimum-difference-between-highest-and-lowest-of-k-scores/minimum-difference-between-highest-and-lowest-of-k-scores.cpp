class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int i=0;
        int j=k-1;
        int minDiff=INT_MAX;
        while(j<nums.size()){
            int minElement=nums[i];
            int maxElement=nums[j];
            minDiff=min(minDiff,(maxElement-minElement));
            i++;
            j++;
            
        }
        return minDiff;
    }
};