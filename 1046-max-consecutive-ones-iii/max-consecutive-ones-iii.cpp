class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        int zeroCnt=0;
        int maxOnes=0;

        int st=0;

        for(int end=0;end<n;end++){
            if(nums[end]==0){
                zeroCnt++;
            }

            while(zeroCnt>k){
                if(nums[st]==0){
                    zeroCnt--;
                }
                st++;
            }
            maxOnes=max(maxOnes, end-st+1);
        }
        return maxOnes;
    }
};