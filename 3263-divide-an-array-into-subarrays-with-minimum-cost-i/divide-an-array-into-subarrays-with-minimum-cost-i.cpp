class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int score=nums[0];

        int firstMin=INT_MAX;
        int secMin=INT_MAX;

        for(int i=1;i<n;i++){
            if(nums[i]<firstMin){
                secMin=firstMin;
                firstMin=nums[i];
            }else if(nums[i]<secMin){
                secMin=nums[i];
            }
        }
        return score+firstMin+secMin;
    }
};